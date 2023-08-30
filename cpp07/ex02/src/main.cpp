/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:48 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:46:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main( void )
{
	Array<int>			empty;
	Array<int>			int_array(5);
	Array<int>			int_array2 = int_array;
	Array<int>			int_array3(int_array);
	Array<char>			char_array(5);
	Array<long>			long_array(7);
	Array<std::string>	str_array(5);

	// for ( unsigned int i = 0; i < empty.size(); i++ ){
	// 	empty[i] = 1;
	// }
	// std::cout << empty << std::endl;
	for ( unsigned int i = 0; i < int_array.size(); i++ ){
		int_array[i] = static_cast<int>(i);
	}
	for ( unsigned int i = 0; i < int_array2.size(); i++ ){
		int_array[i] = static_cast<int>(i);
	}
	std::cout << int_array << std::endl;
	for ( unsigned int i = 0; i < char_array.size(); i++ ){
		char_array[i] = static_cast<char>(i + 32);
	}
	std::cout << char_array << std::endl;
	for ( unsigned int i = 0; i < long_array.size(); i++ ){
		long_array[i] = i;
	}
	std::cout << long_array << std::endl;
	for ( unsigned int i = 0; i < str_array.size(); i++ ){
		str_array[i] = "Hello";
	}
	std::cout << str_array << std::endl;
	try {
		std::cout << int_array[12] << std::endl;
	} catch (Array<int>::OutOfBoundsException & e){
	 	std::cout << "out of bounds access" << std::endl;
	}
	return 0;
}