/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/14 08:11:46 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<int, float>	BitcoinExchange::_dataBase;

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & rhs ){
	
	if( this != &rhs )
		_dataBase = rhs._dataBase;
	return (*this);
}

void BitcoinExchange::initData( void ){

	std::ifstream	rawData;
	std::string		line;
	std::string		key;
	size_t			pos;
	float			value;
	int				flag = 1;

	rawData.open( "data.csv", std::fstream::in );
	checkFileStream(rawData);
	do{
		getline( rawData, line );
		if ( ( line.empty() && !rawData.eof() ) || flag ){
			flag = 0;
			continue ;
		}
		pos = line.find(',');
		key = line.substr( 0, pos );
		value = static_cast<float>( atof( line.substr(pos + 1, line.length() - pos).c_str() ) );
		_dataBase[dateToNum(key)] = value;
	} while ( !rawData.eof() );
	rawData.close();
}

BitcoinExchange::error_code BitcoinExchange::checkAmount( const std::string& str ) {

	double val;
	int period_flag = 0;

	if ( str.c_str()[0] != ' ' )
		return nan;
	for ( size_t i = 1 ; i < str.length(); i++ )
	{
		if( str.c_str()[i] == '.' && !period_flag){
			period_flag = 1;
			i++;
			continue;
		}
		if ( !isdigit( str.c_str()[i] ) && str.c_str()[1] != '-' )
			return nan;
	}
	val = atof(str.c_str());
	if ( val < 0 )
		return small;
	if ( val > 1000 )
		return large;
	return good;
}

void BitcoinExchange::printNumError(error_code error) {

	switch (error){	
		case 1:
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		case 2:
			std::cerr << "Error: too large a number." << std::endl;
			break;
		case 3:
			std::cerr << "Error: bad number." << std::endl;
			break;
		default:
			std::cerr << "Error: unknown error occured." << std::endl;
	}
}

void BitcoinExchange::printValue( std::string * cur_substr)
{
	double	amount;
	double	value;

	std::map<int, float>::const_iterator entry;
	entry = _dataBase.lower_bound(dateToNum(*cur_substr));
	if (entry != _dataBase.begin()) {
		entry--;
	}
	value = atof(cur_substr[1].c_str());
	amount = value * entry->second;
	std::cout << *cur_substr << " => " << value << " = " << amount << std::endl;
}

void BitcoinExchange::getValue( std::string line ){

	std::string	date;
	error_code	num_error;

	std::string* cur_substr = split( line );
	if ( !cur_substr )
		return;
	if (!checkDate(cur_substr[0])) {
		std::cerr << "Error: invalid date => " << cur_substr[0] << std::endl;
		return ;
	}
	if ((num_error = checkAmount(cur_substr[1]))) {
		printNumError(num_error);
		return ;
	} 
	printValue(cur_substr);
	delete [] cur_substr;
}

