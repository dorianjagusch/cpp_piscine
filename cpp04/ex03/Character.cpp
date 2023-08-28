/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:30:16 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("")
{
	for (int i = 0; i < 4; i++){
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 256; i++){
		_unequipped[i] = NULL;
	}
	// std::cout << "Default character constructor called" << std::endl;
}

Character::Character( std::string name ) : _name(name)
{
	for (int i = 0; i < 4; i++){
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 256; i++){
		_unequipped[i] = NULL;
	}
	// std::cout << "Parametric character constructor called" << std::endl;
}

Character::Character( Character const &src )
{
	*this = src;

	// std::cout << "Character copier called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++){
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 256; i++){
		if (_unequipped[i]){
			delete _unequipped[i];
			break;
		}
	}
	// std::cout << "Character destructor called" << std::endl;
}

Character &	Character::operator=( Character const &rhs )
{
	if ( this != &rhs )
	{
		static_cast<std::string>(_name) = rhs._name;
		for (int i = 0; i < 4; i++){
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i];
		}
		// I decided to not transfer the unequipped materials as they are not accessible
		// to anything or anyone and would thus needlessly consume spac
		// if were to I make them identical
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int i;

	for (i = 0; i < 4; i++){
		if (!_inventory[i])
			break ;
	}
	if (i < 4)
		_inventory[i] = m;
	else
		std::cout << _name << " cannot equip " << m->getType() << " anymore" << std::endl;
}

void Character::unequip(int idx)
{
	if ( !( 0 <= idx && idx < 4 ) ){
		std::cout << "Cannot unequip item that does not exist" << std::endl;
		return ;
	}
	for (int i = 0; i < 256; i++){
		if (!_unequipped)
			_unequipped[i] = _inventory[idx];
	}
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if ( !( 0 <= idx && idx < 4 ) ){
		std::cout << "Cannot use item that does not exist" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}