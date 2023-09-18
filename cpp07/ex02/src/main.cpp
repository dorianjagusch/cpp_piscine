/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:48 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 09:27:28 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

// int main( void )
// {
// 	Array<int>			empty;
// 	Array<int>			int_array(5);
// 	Array<int>			int_array2 = int_array;
// 	Array<int>			int_array3(int_array);
// 	Array<char>			char_array(5);
// 	Array<long>			long_array(7);
// 	Array<std::string>	str_array(5);

// 	for ( unsigned int i = 0; i < empty.size(); i++ ){
// 		empty[i] = 1;
// 	}
// 	std::cout << empty << std::endl;
// 	for ( unsigned int i = 0; i < int_array.size(); i++ ){
// 		int_array[i] = static_cast<int>(i);
// 	}
// 	for ( unsigned int i = 0; i < int_array2.size(); i++ ){
// 		int_array[i] = static_cast<int>(i);
// 	}
// 	std::cout << int_array << std::endl;
// 	for ( unsigned int i = 0; i < char_array.size(); i++ ){
// 		char_array[i] = static_cast<char>(i + 32);
// 	}
// 	std::cout << char_array << std::endl;
// 	for ( unsigned int i = 0; i < long_array.size(); i++ ){
// 		long_array[i] = i;
// 	}
// 	std::cout << long_array << std::endl;
// 	for ( unsigned int i = 0; i < str_array.size(); i++ ){
// 		str_array[i] = "Hello";
// 	}
// 	std::cout << str_array << std::endl;
// 	try {
// 		std::cout << int_array[12] << std::endl;
// 	} catch (Array<int>::OutOfBoundsException & e){
// 	 	std::cout << "out of bounds access" << std::endl;
// 	}
// 	try {
// 		std::cout << int_array[-1] << std::endl;
// 	} catch (Array<int>::OutOfBoundsException & e){
// 	 	std::cout << "out of bounds access" << std::endl;
// 	}
// 	return 0;
// }


#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
   Array<int> numbers(MAX_VAL);
   int* mirror = new int[MAX_VAL];
   srand(time(NULL));
   for (int i = 0; i < MAX_VAL; i++)
   {
       const int value = rand();
       numbers[i] = value;
       mirror[i] = value;
   }
   //SCOPE
   {
       Array<int> tmp = numbers;
       Array<int> test(tmp);
   }

   for (int i = 0; i < MAX_VAL; i++)
   {
       if (mirror[i] != numbers[i])
       {
           std::cerr << "didn't save the same value!!" << std::endl;
           return 1;
       }
   }
   try
   {
       numbers[-2] = 0;
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
   try
   {
       numbers[MAX_VAL] = 0;
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }

   for (int i = 0; i < MAX_VAL; i++)
   {
       numbers[i] = rand();
   }
   delete [] mirror;//
   return 0;
}