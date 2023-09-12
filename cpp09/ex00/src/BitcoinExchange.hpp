/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:40 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/12 17:48:45 by djagusch         ###   ########.fr       */
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
	void				getValue( std::string );

private:
	enum error_code{
		good,
		small,
		large,
		nan
	};
	std::map<std::string, float>	_dataBase;
	std::string* split( const std::string& str );
	bool checkDate( const std::string& str );
	bool isDateValid( int year, int month, int day );
	error_code checkAmount( const std::string& str );
	void printNumError( error_code );
};

#endif