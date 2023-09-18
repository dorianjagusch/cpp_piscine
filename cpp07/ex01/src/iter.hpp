/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:11:24 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 09:22:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter( T* array, size_t size, void ( *funct )( T const & ) )
{
	for( size_t i = 0; i < size; i++ ){
		funct(array[i]);
	}
}

template <typename T>
void	iter( T* array, size_t size, void ( *funct )( T & ) )
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

#endif