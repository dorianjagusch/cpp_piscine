/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:17:37 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 08:02:44 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <limits>
# include <cstdlib>
# include <cfloat>
# include <string>

class Converter
{
public:
	static void		convert( std::string const &input );

private:

	class OverflowException : public std::exception
	{
		virtual const char* what( void ) const throw();
	};

	enum {
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	};

	static char		_char;
	static int		_int;
	static float	_float;
	static double	_double;
	static int		_type;
	static bool		_pseudo_literal;
	static bool		_possible;

	Converter ();
	Converter( Converter const &src );
	~Converter();
	Converter &	operator=( Converter const &rhs );

	static bool		_isChar( std::string const &input );
	static bool		_isInt( std::string const &input );
	static bool		_isFloat( std::string const &input );
	static bool		_isDouble( std::string const &input );
	static bool		_isPseudoLiteral( std::string const &input, const int c );
	static bool		_isImpossible( std::string const &input );
	static bool		_isOverflow( std::string const &input );

	static void		_printChar( void );
	static void		_printInt( void );
	static void		_printFloat( std::string const &input );
	static void		_printDouble( std::string const &input );

	static void		_convertValue( void );
	static void		_printConversion( std::string const &input );
};

#endif