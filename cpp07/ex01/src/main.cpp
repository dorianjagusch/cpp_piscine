/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:21:08 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 14:32:42 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <limits>

int main( void ){

	std::cout << "Integters: " << std::endl;
	int ints[] = {0, 2, 4, std::numeric_limits< int >::max(), std::numeric_limits< int >::min()};
	::iter( ints, 5, printArray );
	
	std::cout << std::endl << "Floats: " << std::endl;
	float floats[] = {1, 4, -6.7564f, 7, 8.6576432f, 9, 0};
	::iter( floats, 7, printArray );
	
	std::cout << std::endl << "Const floats: " << std::endl;
	float const floats2[] = {1, 4, -6.7564f, 7, 8.6576432f, 9, 0};
	::iter( floats2, 7, printArray );

	std::cout << std::endl << "Chars: " << std::endl;
	char chars[] = {'a', 'b', 'e', '6', '\n', '\0'};
	::iter( chars, 6, printArray );
	
	std::cout << std::endl << "Strings: " << std::endl;
	std::string strings[] = {"Hello", "bye", "\n", ""};
	::iter( strings, 4, printArray );

	return 0;
}