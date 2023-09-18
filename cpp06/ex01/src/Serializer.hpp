/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:42:07 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 07:45:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISER_HPP
# define SERIALISER_HPP

# include "Data.hpp"

typedef unsigned long int	uintptr_t;

class Serializer
{
public:
	static uintptr_t	serialize( Data* ptr );
	static Data*		deserialize( uintptr_t raw );
private:
	Serializer ();
	Serializer( Serializer const &src );
	~Serializer();
	Serializer &	operator=( Serializer const &rhs );
};

#endif

