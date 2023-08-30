/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:26 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat initialised" << std::endl;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal(src)
{
  *this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat obliterated" << std::endl;
}

WrongCat &	WrongCat::operator=( WrongCat const &rhs )
{
	if ( this != &rhs );
	_type = rhs._type;
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Your opinion does not concern me, human" << std::endl;
}
