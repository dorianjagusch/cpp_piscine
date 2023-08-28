/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:26 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( ) : Animal("Cat")
{
	std::cout << "Cat initialised" << std::endl;
}

Cat::Cat( Cat const &src ) : Animal(src)
{
  *this = src;
}

Cat::~Cat()
{
	std::cout << "Cat obliterated" << std::endl;
}

Cat &	Cat::operator=( Cat const &rhs )
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Your opinion does not concern me, human" << std::endl;
}
