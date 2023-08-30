/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:30:20 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("nemo"), _health(1), _energy(0), _damage(0)
{
	std::cout << "ClapTrap " << _name << " exists somehow" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << name << " came into existence" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	*this = src;
}

std::string ClapTrap::getName( void ) const
{
	return _name;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const &rhs )
{
	if (this != &rhs)
		_name = rhs._name;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "The body of ClapTrap " << _name << " has been absorbed by the ether..." << std::endl;
	std::cout << "We will miss you... friend." << std::endl;
}


void ClapTrap::_no_energy( void ) const
{
	std::cout << "ClapTrap " << _name << " is out of energy" << std::endl;
}

void ClapTrap::_is_dead( void ) const
{
	std::cout << "ClapTrap " << _name << " is dead" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy == 0)
	{
		_no_energy();
		return ;
	}
	if (_health == 0)
	{
		_is_dead();
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", inflicting " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_health == 0)
	{
		_is_dead();
		return ;
	}
	std::cout << "ClapTrap " << _name << " lost " << amount << " health points";
	_health -= amount;
	if ((unsigned long)(_health <= 0))
	{
		std::cout << " and died";
		_health = 0;
	}
	std::cout << "!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_health == 0)
	{
		_is_dead();
		return ;
	}
	if (_energy == 0)
	{
		_no_energy();
		return ;
	}
	std::cout << "ClapTrap " << _name << " restores " << amount << " health points!" << std::endl;
	_health += amount;
	_energy--;
}