/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:48:53 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("None")
{
	std::cout << "Random animal initialised" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
}

WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
  *this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Random animal obliterated" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const &rhs )
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

std::string	WrongAnimal::getType( void ) const
{
	return _type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "* Indistinguishable animal sounds *" << std::endl;
}
