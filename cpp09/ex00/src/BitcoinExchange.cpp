/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:20 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define MONTH_SCALE int( 10e1 )
#define YEAR_SCALE int( 10e3 )

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
		_dataBase[dateToNum(key)] = value;
	} while ( !rawData.eof() );
	rawData.close();
}

bool BitcoinExchange::checkDate( const std::string& str ) {

	size_t i = 0;

	for ( ; i < str.length(); i++ )
	{
		if ( i != 4 && i != 7){
			if ( !isdigit( str.c_str()[i] ) )
				break ;
		} else if ( str.c_str()[i] != '-' )
			return false;
	}
	if ( i != str.length() - 1 || str.c_str()[i] != ' ' || str.c_str()[i + 1] != '\0')
		return false;
	return isDateValid( dateToNum(str) );
}

BitcoinExchange::error_code BitcoinExchange::checkAmount( const std::string& str ) {

	double val;
	int period_flag;

	if ( str.c_str()[0] != ' ' )
		return nan;
	for ( size_t i = 1 ; i < str.length(); i++ )
	{
		if( str.c_str()[i] == '.' && !period_flag){
			period_flag = 1;
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

void BitcoinExchange::getValue( std::string line ){

	std::string	date;
	double		amount;
	error_code	num_error;
	double		value;

	std::string* cur_substr = split( line );
	if ( cur_substr ){
		if (!checkDate(cur_substr[0])) {
			std::cerr << "Error: invalid date => " << cur_substr[0] << std::endl;
		} else if ((num_error = checkAmount(cur_substr[1]))) {
			printNumError(num_error);
		} else {
			std::map<int, float>::const_iterator entry;
			entry = _dataBase.lower_bound(dateToNum(*cur_substr));
			if (entry != _dataBase.begin()) {
				entry--;
			}
			value = atof(cur_substr[1].c_str());
			amount = value * entry->second;
			std::cout << *cur_substr << " => " << value << " = " << amount << std::endl;
			}
	}
	delete [] cur_substr;
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

//Date functions

int BitcoinExchange::dateToYear( int date ){ return date / YEAR_SCALE; }

int BitcoinExchange::dateToMonth( int date ){ return ( date - dateToYear(date) * YEAR_SCALE ) / MONTH_SCALE; }

int BitcoinExchange::dateToDay( int date ){ return date - dateToYear(date) * YEAR_SCALE - dateToMonth(date) * MONTH_SCALE; }

int BitcoinExchange::dateToNum(std::string const & str) {

	int day, month, year, date;

	year = atoi( str.c_str() );
	month = atoi( str.c_str() + 5 );
	day = atoi( str.c_str() + 8 );
	date = year * YEAR_SCALE + month * MONTH_SCALE + day;
	return date;
}
std::string BitcoinExchange::numToDate(int date) {

	int day, month, year;
	std::stringstream stream;

	year = dateToYear( date );
	month = dateToMonth( date );
	day = dateToDay( date );
	stream << year << '-' << month << '-' << day;
	std::string result = stream.str();
	std::cout << "result: " << date << std::endl;
	return result;
}

bool BitcoinExchange::isLeapYear( int year ) {
	
	if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) )
		return true;
	return false;
}

bool BitcoinExchange::isDateValid( int date ) {

	int day, month, year;

	day = dateToDay( date );
	month = dateToMonth( date );
	year = dateToYear( date );

	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ( day < 1 
	|| ( day > 31 && (month == 1 || month == 3 || month == 5 
		|| month == 7 || month == 8 || month == 10 || month == 12) )
	|| ( day > 30 && ( month == 4 || month == 6 || month == 9 || month == 11 ) )
	|| ( day > 28 + static_cast<int>(isLeapYear(year)) && month == 2 ) )
		return false;
	return true;
}
