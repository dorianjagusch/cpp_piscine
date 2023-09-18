/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:30:38 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 07:52:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("unkown"), _occupation("unknown")
{}

Data::Data( std::string name, std::string occupation )
	: _name(name), _occupation(occupation)
{
}

Data::Data( Data const &src )
{
	*this = src;
}

Data::~Data()
{}

Data &	Data::operator=( Data const &rhs )
{
	if( this != &rhs )
		static_cast<void>( rhs );
	return *this ;
}