/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:52 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;
	int		input = 0;
		std::string	type[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};

	if (ac != 2)
	{
		std::cout << "Provide one argument, please" << std::endl;
		return 1;
	}
	while (input < 4)
	{
		if (type[input].length() && type[input] == av[1])
			break ;
		input++;
	}
	switch (input){
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain((std::string)"DEBUG");
			std::cout << std::endl;
			// intentional fall-through
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
			// intentional fall-through
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			// intentional fall-through
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}