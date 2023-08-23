/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:30:47 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:42:39 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <Cure.hpp>

Cure::Cure()
{}

Cure::Cure( Cure const & src )
{
  *this = src;
}

Cure::~Cure()
{}

Cure &	Cure::operator=( Cure const & rhs )
{
	if( this == &rhs )
		_ATRIBUTE = rhs.ATTRIBUTE;
	return (*this);
}