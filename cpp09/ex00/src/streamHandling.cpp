/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streamHandling.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:56:33 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/28 09:08:53 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::checkFileStream( std::ifstream & stream ){
	if (!stream.is_open() || !stream.good() || stream.peek() < 0){
		std::cerr << "Failed to open input file." << std::endl;
		stream.close();
		exit(1);
	}
}

std::string* BitcoinExchange::split( const std::string& str ) {

	std::string* 		tokens = new std::string[4];
	std::istringstream	stream(str);
	std::string			token;
	size_t				i = 0;

	for( ; i < 4 && std::getline( stream, token, '|' ); i++) {
		tokens[i] = ( token );
	}
	if ( i != 2){
		delete [] tokens;
		std::cerr << "Error: bad input => " << str << std::endl;
		return NULL;
	}
	return (tokens);
}