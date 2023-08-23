/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:30:16 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:42:27 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{}

Character::Character( Character const & src )
{
  *this = src;
}

Character::~Character()
{}

Character &	Character::operator=( Character const & rhs )
{
	if ( this == &rhs )
		_ATRIBUTE = rhs.ATTRIBUTE;
	return (*this);
}