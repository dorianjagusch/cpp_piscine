/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:48:53 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 20:32:08 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("None")
{
	std::cout << "Random animal initialised" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type(type)
{
}

AAnimal::AAnimal( AAnimal const & src )
{
	_type = src._type;
}

AAnimal::~AAnimal()
{
	std::cout << "Random animal obliterated" << std::endl;
}

AAnimal &	AAnimal::operator=( AAnimal const & rhs )
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (_type);
}

