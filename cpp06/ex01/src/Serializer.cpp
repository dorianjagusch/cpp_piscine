/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:08:46 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer( Serializer const &src )
{
	*this = src;
}

Serializer::~Serializer()
{}

Serializer &	Serializer::operator=( Serializer const &rhs )
{
	if( this != &rhs )
		static_cast<void>( rhs );
	return *this ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>( ptr );
}


Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast< Data* >( raw );
}