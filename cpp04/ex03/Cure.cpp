/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:31:17 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default contructor called" << std::endl;
}

Cure::Cure( Cure const &src ) : AMateria(src)
{
	*this = src;
	// std::cout << "Cure copier called" << std::endl;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure &	Cure::operator=( Cure const &rhs )
{
	// std::cout << "Cure assignment called" << std::endl;
	if( this != &rhs )
		_type = rhs.getType();
	return *this;
}

void		Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone() const
{
	Cure *cure = new Cure(*this);

	if (!cure)
		std::cerr << "Memory allocation failed" << std::endl;
	return cure;
}