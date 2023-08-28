/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:21:08 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 14:33:42 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <limits>

int main( void ){
	int				ints[] = {0, 2, 4, std::numeric_limits< int >::max(), std::numeric_limits< int >::min()};
	float			floats[] = {1, 4, -6.7564f, 7, 8.6576432f, 9, 0};
	char			chars[] = {'a', 'b', 'e', '6', '\n', '\0'};
	std::string		strings[] = {"Hello", "bye", "\n", ""};

	std::cout << "Integters: " << std::endl;
	::iter(ints, 5, printArray);
	std::cout << std::endl << "Floats: " << std::endl;
	::iter(floats, 7, printArray);
	std::cout << std::endl << "Chars: " << std::endl;
	::iter(chars, 6, printArray);
	std::cout << std::endl << "Strings: " << std::endl;
	::iter(strings, 4, printArray);

	return (0);
}