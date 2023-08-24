/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:31:17 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/24 23:05:27 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default contructor called" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
	*this = src;
	// std::cout << "Ice copier called" << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice &	Ice::operator=( Ice const & rhs )
{
	// std::cout << "Ice assignment called" << std::endl;
	if( this != &rhs )
		_type = rhs.getType();
	return (*this);
}

void		Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	Ice *ice = new Ice(*this);

	if (!ice)
		std::cerr << "Memory allocation failed" << std::endl;
	return (ice);
}