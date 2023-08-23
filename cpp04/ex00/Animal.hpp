/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:40:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 18:16:21 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal( Animal const & src );
	virtual ~Animal();

	Animal &		operator=( Animal const & rhs );
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;

protected:
	Animal( std::string type );
	std::string _type;
};

#endif