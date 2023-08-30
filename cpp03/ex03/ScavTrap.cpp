/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:29:46 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_damage = 20;

	std::cout << "and rises as ScavTrap " << _name << " from the depths of Hell" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap(src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
 	std::cout << "After a long arduous fight against the forces of nature.";
	std::cout << " ScavTrap " << _name << " succumbs to their injuries..." << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const &rhs )
{
	if (this->_name != rhs.getName())
		*this = rhs;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
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
	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", inflicting " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ScavTrap::guardGate( void ) const
{
	if (_health == 0)
	{
		_is_dead();
		return ;
	}
	std::cout << "ScavyTrap " << _name << " says: \"Girlboss, Gaslighting, Gatekeep\"" << std::endl;
}

