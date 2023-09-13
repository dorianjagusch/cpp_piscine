/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 11:53:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int ac, char **argv){
	
	if (ac != 2){
		std::cerr << "Error: Provide one input file, please" << std::endl;
		return 1;
	}
	std::ifstream inFile;
	inFile.open( argv[1], std::fstream::in );
	if ( !inFile.is_open() || !inFile.good() || inFile.peek() < 0 ){
		std::cerr << "Failed to open input file" << std::endl;
		return 2;
	}
	BitcoinExchange::initData();
	std::string		line;
	while ( !inFile.eof() ){
		getline( inFile, line );
		if ( !line.empty() )
			BitcoinExchange::getValue( line );
	}
	inFile.close();
	return 0;
}