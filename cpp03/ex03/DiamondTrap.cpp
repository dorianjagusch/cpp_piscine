/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:29:46 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 23:42:46 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "clap_trap")
{
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_name = name;

	std::cout << "and rises as DiamondTrap " << _name << " from the sewers" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	*this = src;
}

DiamondTrap::~DiamondTrap( void )
{
 	std::cout << "I am out of ideas.";
	std::cout << " DiamondTrap goes back to the sewers, I guess." << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (this->_name != rhs.getName())
		*this = rhs;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) const
{
	if (_health == 0)
	{
		this->is_dead();
		return ;
	}
	std::cout << "DiamondTrap " << _name << " explains that their close friends call them by their " << std::endl;
		std::cout << "ClapTrap name: " << ClapTrap::_name << "." << std::endl;
}

