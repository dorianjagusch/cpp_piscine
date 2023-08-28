/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:29:46 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_damage = 30;

	std::cout << "and rises as FragTrap " << _name << " from the cracks in the ice" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap(src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
 	std::cout << "After a long arduous fight against the forces of nature.";
	std::cout << " FragTrap " << _name << " succumbs to their injuries..." << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const &rhs )
{
	if (this->_name != rhs.getName())
		*this = rhs;
	return (*this);
}

void	FragTrap::HighFiveGuys( void )
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
	std::cout << "FragTrap " << _name << " solemnly raises their hand to about eye height." << std::endl;
	std::cout << " You hestitate. Could this really ... mean what you think it does?" << std::endl;
	std::cout << " You approach with an outstreched arm - first cautiously then more confidently - " << std::endl;
	std::cout << " as your palms meet each other emitting ther glorious ring of triumph." << std::endl;
	this->_energy--;
}

