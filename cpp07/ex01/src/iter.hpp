/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:11:24 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:45:09 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter( T* array, size_t size, void ( *funct )( T const & ) )
{
	for( size_t i = 0; i < size; i++ ){
		funct(array[i]);
	}
}

template <typename T>
void	printArray( T const &value )
{
	std::cout << value << std::endl;
}
