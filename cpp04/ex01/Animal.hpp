/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:40:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
public:
	Animal();
	Animal( Animal const &src );
	virtual ~Animal();

	Animal &		operator=( Animal const &rhs );
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;

protected:
	Animal( std::string type );
	std::string _type;
};

#endif