/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:13:31 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/20 21:45:50 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cstdio>

std::string getInput( void )
{
	char input[256];

	while (!std::cin.getline(input, 256))
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ((std::string)"");
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input too long. Try again." << std::endl;
			return ((std::string)"");
		}
	}
	return input;
}

int main( void )
{
	PhoneBook	phonebook;
	std::string	input = "";
	bool		flag = 0;

	do {
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
		{
			if (flag)
				std::cout << "Invalid command. ";
			flag = 1;
		}
		if (!std::cin.eof())
			std::cout << "What would you like to do? (ADD, SEARCH, EXIT)" << std::endl;
		else
			std::cout << std::endl;
		input = getInput();
	} while (!std::cin.eof() && input != "EXIT");
	return (0);
}