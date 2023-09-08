/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/08 18:19:54 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>


int main(int ac, char **argv)
{
	std::ifstream	rawData;
	std::map<std::string, float>	dataBase;


	if (ac != 2){
		std::cerr << "Error: Provide one input file, please" << std::endl;
		return 1;
	}

	rawData.open("data.csv", std::fstream::in);
	if (!rawData.is_open() || !rawData.good()){
		std::cerr << "Failed to open input file." << std::endl;
		return 2;
	}

	return 0;
}