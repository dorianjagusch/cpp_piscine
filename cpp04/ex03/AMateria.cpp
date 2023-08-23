/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:29:41 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:42:17 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria( AMateria const & src )
{
  *this = src;
}

AMateria::~AMateria()
{}

AMateria &	AMateria::operator=( AMateria const & rhs )
{
	if( this == &rhs )
		_ATRIBUTE = rhs.ATTRIBUTE;
	return (*this);
}