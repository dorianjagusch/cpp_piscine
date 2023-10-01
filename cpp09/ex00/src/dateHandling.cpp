/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dateHandling.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:54:28 by djagusch          #+#    #+#             */
/*   Updated: 2023/10/01 21:04:48 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define MONTH_SCALE int( 10e1 )
#define YEAR_SCALE int( 10e3 )

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
std::string BitcoinExchange::numToDate( int date ) {

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

	if ( year < 2009 || date == 20090101 )
		return false;
	if ( month < 1 || month > 12 )
		return false;
	if ( day < 1
	|| ( day > 31 && (  month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10 || month == 12 ) )
	|| ( day > 30 && ( month == 4 || month == 6 || month == 9 || month == 11 ) )
	|| ( day > 28 + static_cast<int>( isLeapYear( year ) ) && month == 2 ) )
		return false;
	return true;
}