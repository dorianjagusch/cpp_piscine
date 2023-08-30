/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:59 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( ) : Animal("Dog")
{
	std::cout << "Dog initialised" << std::endl;
}

Dog::Dog( Dog const &src ) : Animal(src)
{
  *this = src;
}

Dog::~Dog()
{
	std::cout << "Dog obliterated" << std::endl;
}

Dog &	Dog::operator=( Dog const &rhs )
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "I'm a good boi" << std::endl;
}
