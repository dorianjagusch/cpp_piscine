/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:17:54 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/21 17:55:04 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
}

Zombie::~Zombie( void )
{
	std::cout << _name << ": I dead" << std::endl;
}

void Zombie::announce (void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}