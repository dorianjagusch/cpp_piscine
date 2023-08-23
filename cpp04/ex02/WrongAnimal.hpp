/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:40:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:36 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal( WrongAnimal const & src );
	virtual ~WrongAnimal();

	WrongAnimal &		operator=( WrongAnimal const & rhs );
	std::string		getType( void ) const;
	void	makeSound( void ) const;

protected:
	WrongAnimal( std::string type );
	std::string _type;
};

#endif