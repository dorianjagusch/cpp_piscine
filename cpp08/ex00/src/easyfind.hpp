/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:05:15 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 10:34:43 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <algorithm>
#include <typeinfo>

class NotFoundException;

template<typename T>
typename T::const_iterator 	easyfind(const T& container, int needle)
{
	typename T::const_iterator beginning = container.begin();
	if( typeid(*beginning) != typeid(int) )
		throw( std::invalid_argument("Container elements must be of type int") );

	typename T::const_iterator end = container.end();
	typename T::const_iterator result = find( beginning, end, needle );
	if ( result == end )
		throw ( NotFoundException() );
	return result;
}