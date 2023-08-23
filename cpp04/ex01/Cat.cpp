/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:26 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 20:14:34 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( ) : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat initialised" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	_brain = new Brain(*(src._brain));
	if (!_brain)
		std::cerr << "Memory allocation failed" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat obliterated" << std::endl;
	if (_brain)
		delete _brain;
}

Cat &	Cat::operator=( Cat const & rhs )
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
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Your opinion does not concern me, human" << std::endl;
}
