/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:40 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/09 18:16:30 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
public:
	BitcoinExchange ();
	BitcoinExchange( BitcoinExchange const & src );
	~BitcoinExchange();

	BitcoinExchange &	operator=( BitcoinExchange const & rhs );
	std::string 		getValue( std::string );

private:
	std::map<std::string, float>	_dataBase;
	std::string*					cur_substr;

};

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	rawData;
	std::string		line;
	std::string		key;
	size_t			pos;
	float			value;

	rawData.open("data.csv", std::fstream::in);
	if (!rawData.is_open() || !rawData.good() || rawData.peek() < 0){
		std::cerr << "Failed to open input file." << std::endl;
		rawData.close();
		exit(1);
	}
	do{
		getline( rawData, line );
		if ( line.empty() && !rawData.eof() )
			continue ;
		pos = line.find(',');
		key = line.substr( 0, pos );
		value = static_cast<float>(atof(line.substr(pos + 1, line.length() - pos).c_str()));
		_dataBase[key] = value;
	} while ( !rawData.eof() );
	rawData.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if( this != &rhs )
		_dataBase = rhs._dataBase;
	return (*this);
}

std::string* split(const std::string& str, char delimiter) {
	std::string* 		tokens = new std::string[4];
	std::istringstream	stream(str);
	std::string			token;
	int					i = 0;

	for( ; i < 4 && std::getline(stream, token, '|'); i++) {
			tokens[i] = (token);
	}
	if ( i != 2){
		delete [] tokens;
		tokens = NULL;
	}
	return (tokens);
}

std::string BitcoinExchange::getValue( std::string line )
{
	std::istringstream	stream(line);
	std::string			token;
	int					i = 0;

	for( ; i < 4 && std::getline(stream, token, '|'); i++) {
			cur_substr[i] = (token);
	}
	if ( i != 2){
		delete [] cur_substr;
		cur_substr = NULL;
	}
	while ( cur_substr ){
		std::getline(cur_substr, token, '|')
	}
	delete [] cur_substr;
}

#endif