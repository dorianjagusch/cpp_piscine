/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:48:53 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("None")
{
	std::cout << "Random animal initialised" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
}

Animal::Animal( Animal const &src )
{
  *this = src;
}

Animal::~Animal()
{
	std::cout << "Random animal obliterated" << std::endl;
}

Animal &	Animal::operator=( Animal const &rhs )
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

std::string	Animal::getType( void ) const
{
	return _type;
}

void Animal::makeSound( void ) const
{
	std::cout << "* Indistinguishable animal sounds *" << std::endl;
}
