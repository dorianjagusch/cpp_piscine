/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:31:40 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 11:48:27 by djagusch         ###   ########.fr       */
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
	~BitcoinExchange();

	static void	initData( void );
	static void	getValue( std::string );

private:
	enum error_code{
		good,
		small,
		large,
		nan
	};
	static std::map<int, float>	_dataBase;

	static std::string*	split( const std::string & );

	static error_code	checkAmount( const std::string & );
	static bool			checkDate( const std::string & );
	static void			printNumError( error_code );

	static bool			isDateValid( int );
	static bool			isLeapYear( int );
	static int			dateToNum(std::string const & );
	static std::string	numToDate(int);
	static int			dateToYear( int );
	static int			dateToMonth( int );
	static int			dateToDay( int );

	BitcoinExchange( BitcoinExchange const & );
	BitcoinExchange &	operator=( BitcoinExchange const & );
};

#endif