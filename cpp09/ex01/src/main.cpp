/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 09:20:31 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <fstream>
#include <string>

#include <stack>

int main(int ac, char **argv){
	if (ac != 2)
	{
		std::cerr << "Error: provide input as a single string." << std::endl;
		return 1;
	}
	RPN::DoTheThing(argv[1]);
	
	// std::string str;

	// str = " 12 30 +";
	// std::cout << "Test 1: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = " 203425258 204234560 + 5 * 23 -";
	// std::cout << std::endl << "Test 2: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = " 6 12 * / 6 - 60";
	// std::cout << std::endl << "Test 3: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "23 1 - 34 + 34434 - 3434 - 3445 * 23";
	// std::cout << std::endl << "Test 4: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "+-";
	// std::cout << std::endl << "Test 5: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "&efghth";
	// std::cout << std::endl << "Test 6: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "200000000 * 2";
	// std::cout << std::endl << "Test 7: " << str << std::endl;
	// RPN::DoTheThing( str ); //fail

	// str = "50 25 /";
	// std::cout << std::endl << "Test 8: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "25 24 /";
	// std::cout << std::endl << "Test 9: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "25 0 /";
	// std::cout << std::endl << "Test 10: " << str << std::endl;
	// RPN::DoTheThing( str ); //f

	// str = "    ";
	// std::cout << std::endl << "Test 11: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "2342345 + 234";
	// std::cout << std::endl << "Test 12: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "+ 235 2234";
	// std::cout << std::endl << "Test 13: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "23 - 2343454";
	// std::cout << std::endl << "Test 14: " << str << std::endl;
	// RPN::DoTheThing( str );

	// str = "34          343    *     ";
	// std::cout << std::endl << "Test 15: " << str << std::endl;
	// RPN::DoTheThing( str );
	// return 0;
}