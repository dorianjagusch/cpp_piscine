/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:13:56 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:43:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{}

MateriaSource::MateriaSource( MateriaSource const & src )
{
  *this = src;
}

MateriaSource::~MateriaSource()
{}

MateriaSource &	MateriaSource::operator=( MateriaSource const & rhs )
{
	if( this == &rhs )
		_ATRIBUTE = rhs.ATTRIBUTE;
	return (*this);
}
