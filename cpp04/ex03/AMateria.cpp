/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:29:41 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/24 23:05:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
	// std::cout << "AMateria default contructor called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	// std::cout << "AMateria Parametric contructor called" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
	*this = src;
	// std::cout << "AMateria copier called" << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria &	AMateria::operator=( AMateria const & rhs )
{
	// std::cout << "AMateria assignment called" << std::endl;
	if( this != &rhs )
		_type = rhs.getType();
	return (*this);
}

std::string const &	AMateria::getType() const
{
	// std::cout << "AMateria copier called" << std::endl;
	return (_type);
}

void		AMateria::use( ICharacter& target )
{
		std::cout << "Materia" << _type << " used on " << target.getName() << std::endl;
}