/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/12 18:22:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	rawData;
	std::string		line;
	std::string		key;
	size_t			pos;
	float			value;
	int flag = 1;

	rawData.open( "data.csv", std::fstream::in );
	if (!rawData.is_open() || !rawData.good() || rawData.peek() < 0){
		std::cerr << "Failed to open input file." << std::endl;
		rawData.close();
		exit(1);
	}
	do{
		getline( rawData, line );
		if ( ( line.empty() && !rawData.eof() ) || flag ){
			flag = 0;
			continue ;
		}
		pos = line.find(',');
		key = line.substr( 0, pos );
		value = static_cast<float>( atof( line.substr(pos + 1, line.length() - pos).c_str() ) );
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

std::string* BitcoinExchange::split( const std::string& str ) {
	std::string* 		tokens = new std::string[4];
	std::istringstream	stream(str);
	std::string			token;
	size_t				i = 0;

	for( ; i < 4 && std::getline(stream, token, '|'); i++) {
		tokens[i] = (token);
	}
	if ( i != 2){
		delete [] tokens;
		std::cerr << "Error: bad input => " << str << std::endl;
		return NULL;
	}
	return (tokens);
}

bool BitcoinExchange::isDateValid( int year, int month, int day ){
	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ( day < 1 
	|| ( day > 31 && (month == 1 || month == 3 || month == 5 
		|| month == 7 || month == 8 || month == 10 || month == 12) )
	|| ( day > 30 && ( month == 4 || month == 6 || month == 9 || month == 11 ) )
	|| ( day > 28 && month == 2 && year % 4 != 0 )
	|| ( day > 29 &&month == 2 && year % 4 == 0))
		return false;
	return true;
}

bool BitcoinExchange::checkDate( const std::string& str ){
	int day, month, year;
	size_t i = 0;

	std::cout << "str: " << str << std::endl;
	for ( ; i < str.length(); i++ )
	{
		std::cout << i << ": " << str.c_str() << std::endl;
		if ( i != 4 && i != 7){
			if ( !isdigit( str.c_str()[i] ) )
				return false;
		} else if ( str.c_str()[i] != '-' )
			return false;
	}
	if ( str.c_str()[i] != ' ' && str.c_str()[i] != '\0')
		return false;
	year = atoi( str.c_str() );
	std::cout << "year " << str << std::endl;
	month = atoi( str.c_str() + 5 );
	std::cout << "month " << str << std::endl;
	day = atoi( str.c_str() + 8 );
	std::cout << "day " << str << std::endl;
	return isDateValid(year, month, day) ;
}

BitcoinExchange::error_code BitcoinExchange::checkAmount( const std::string& str ){
	double val;
	int period_flag;

	if ( str.c_str()[0] != ' ' )
		return nan;
	for ( size_t i = 0 ; i < str.length(); i++ )
	{
		if( str.c_str()[i] == '.' && !period_flag){
			period_flag = 1;
			continue;
		}
		if ( !isdigit( str.c_str()[i] ) || str.c_str()[1] != '-' )
			return nan;
	}
	val = atof(str.c_str());
	if ( val < 0 )
		return small;
	if ( val > 1000 )
		return large;
	return good;
}

void BitcoinExchange::printNumError(error_code error){
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

void BitcoinExchange::getValue( std::string line )
{
	std::string			date;
	double				amount;
	error_code			num_error;
	double				value;

	printf("%s\n", line.c_str());
	std::string* cur_substr = split( line );
	if ( cur_substr ) {
		printf("%s\n", cur_substr[0].c_str());
		printf("%s\n", cur_substr[1].c_str());
		if ( !this->checkDate( cur_substr[0] ) )
			std::cerr << "Error: invalid date => " << cur_substr[0] << std::endl << std::endl;
		else if ( ( num_error = this->checkAmount( cur_substr[1] ) ) )
			printNumError( num_error );
		else{
			value = atof(cur_substr[1].c_str());
			amount = value * _dataBase[*cur_substr];
			std::cout << cur_substr << " => " << amount << " = " << value << std::endl << std::endl;
		}
		delete [] cur_substr;
	}
}