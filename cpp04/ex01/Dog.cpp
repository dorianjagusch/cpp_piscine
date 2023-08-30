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

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog initialised" << std::endl;
}

Dog::Dog( Dog const &src ) : Animal(src)
{
	_brain = new Brain(*(src._brain));
	if (!_brain)
		std::cerr << "Memory allocation failed" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog obliterated" << std::endl;
	if (_brain)
		delete _brain;
}

Dog &	Dog::operator=( Dog const &rhs )
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (_brain)
			delete _brain;
		_brain = new Brain(*(rhs._brain));
		if (!_brain)
			std::cerr << "Memory allocation failed" << std::endl;
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "I'm a good boi" << std::endl;
}
