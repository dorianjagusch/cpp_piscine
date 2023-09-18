/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:20 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 08:21:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Input error: ./ScalarConverter <input>" << std::endl;
		return 1;
	}
	std::string str = av[1];
	Converter::convert(str);
	return 0;
}