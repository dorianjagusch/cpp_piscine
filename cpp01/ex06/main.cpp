/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:52 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 09:55:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;
	int input;

	if (ac !=2)
		std::cout << "Provide one argument, please" << std::endl;
	for (input = 0; input < 4; input++)
	{
		if (type[input].length() && type[input] == level)
			break ;
	}
	switch (av[1])
	{
		case "DEBUG":
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case "INFO":
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case "WARNING":
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case "Error":
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}