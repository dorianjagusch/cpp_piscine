/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:31:17 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:42:04 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <Ice.hpp>

Ice::Ice()
{}

Ice::Ice( Ice const & src )
{
  *this = src;
}

Ice::~Ice()
{}

Ice &	Ice::operator=( Ice const & rhs )
{
	if( this == &rhs )
		_ATRIBUTE = rhs.ATTRIBUTE;
	return (*this);
}