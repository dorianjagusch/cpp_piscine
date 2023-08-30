/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:25:40 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 08:23:09 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ), _weapon( NULL )
{
}

HumanB::~HumanB()
{
}

void HumanB::attack( void ) const
{
	if ( _weapon && _weapon->getType() != "" )
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " is empty-handed" << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}