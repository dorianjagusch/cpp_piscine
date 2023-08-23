/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:29:46 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 20:24:34 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name )
{
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "and rises as DiamondTrap " << _name << " from the sewers" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap( src ),  ScavTrap( src ), FragTrap( src )
{
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
 	std::cout << "I am out of ideas.";
	std::cout << " DiamondTrap goes back to the sewers, I guess." << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (_name != rhs._name)
		_name = rhs._name;
	return (*this);
}

void	DiamondTrap::whoAmI( void ) const
{
	if (_health == 0)
	{
		this->is_dead();
		return ;
	}
	std::cout << "DiamondTrap " << _name << " explains that their close friends call them by their ";
	std::cout << "ClapTrap name: " << ClapTrap::_name << "." << std::endl;
}

