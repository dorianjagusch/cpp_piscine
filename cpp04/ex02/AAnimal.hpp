/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:40:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 18:50:37 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
public:
	AAnimal();
	AAnimal( AAnimal const &src );
	virtual ~AAnimal();

	AAnimal &		operator=( AAnimal const &rhs );
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;

protected:
	std::string _type;
	AAnimal( std::string type);
};

#endif