/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:26 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( ) : AAnimal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat initialised" << std::endl;
}

Cat::Cat( Cat const &src ) : AAnimal(src)
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

Cat &	Cat::operator=( Cat const &rhs )
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
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Your opinion does not concern me, human" << std::endl;
}
