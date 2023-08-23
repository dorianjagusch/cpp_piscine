/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:59 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 21:02:57 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog initialised" << std::endl;
}

Dog::Dog( Dog const & src ) : AAnimal(src)
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

Dog &	Dog::operator=( Dog const & rhs )
{
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		if (_brain)
			delete _brain;
		_brain = new Brain(*(rhs._brain));
		if (!_brain)
			std::cerr << "Memory allocation failed" << std::endl;
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "I'm a good boi" << std::endl;
}
