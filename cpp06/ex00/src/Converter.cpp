/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:11:53 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


Converter::Converter()
{}

Converter::Converter( Converter const &src )
{
	(void) src;
}

Converter::~Converter()
{}

Converter &	Converter::operator=( Converter const &rhs )
{
	if ( this != &rhs )
		static_cast<void>( rhs );
	return *this;
}

bool		Converter::_isOverflow( std::string const &input )
{
	long long tmp = strtoll( input.c_str(), NULL, 10 );

	if ( tmp > std::numeric_limits< int >::max()
		|| std::numeric_limits< int >::min() > tmp )
		return true ;
	return false ;
}

bool	Converter::_isChar( std::string const &input )
{

	if ( input.length() != 1 || isdigit(input[0]) )
		return false ;
	if ( !std::isprint(input[0]))
		return false ;
	return true ;
}

bool	Converter::_isInt( std::string const &input )
{
	int		offset = 0;
	size_t	i = 0;

	if ( input[0] == '+' || input[0] == '-' )
		offset++;
	for ( i = offset; i < input.length(); i++ )
	{
		if ( !std::isdigit(input[i]) )
			return false ;
	}
	return true ;
}

bool	Converter::_isFloat( std::string const &input )
{
	int		dot = 0;
	int		offset = 0;
	size_t	i = 0;

	if ( _isPseudoLiteral(input, 'f') )
		return true ;
	if ( input[0] == '+' || input[0] == '-' )
		offset++;
	for ( i = offset; i < input.length() - 1; i++ )
	{
		if ( !std::isdigit(input[i]) && input[i] != '.' )
			return false ;
		else if ( input[i] == '.' )
			dot++;
	}
	if ( input[input.length() - 1] != 'f' )
		return false ;
	return true ;
}

bool	Converter::_isDouble( std::string const &input)
{
	int		dot = 0;
	int		offset = 0;
	size_t	i = 0;

	if (_isPseudoLiteral(input, 'd'))
		return true ;
	if (input[0] == '+' || input[0] == '-')
		offset++;
	for ( i = offset; i < input.length(); i++ )
	{
		if ( !std::isdigit(input[i]) && input[i] != '.' )
			return false ;
		else if ( input[i] == '.' )
			dot++;
	}
	return true ;
}

bool	Converter::_isPseudoLiteral(std::string const &input, const int c)
{
	if ( (c == 'f' && ( input == "inff" || input == "-inff" || input == "nanf") )
		|| ( c == 'd' && ( input == "inf" || input == "-inf" || input == "nan") ) ){
		_pseudo_literal = true;
		return true ;
	}
	return false ;
}

bool	Converter::_isImpossible( std::string const &input)
{
	try {
		switch (_type){
			case CHAR:
				_char = static_cast< char >(input[0]);
				break ;
			case INT:
				if (_isOverflow( input ) )
					throw (OverflowException());
				_int = atoi( input.c_str() );
				break ;
			case FLOAT:
				_float = static_cast< float >(strtof( input.c_str(), NULL ) );
				break ;
			case DOUBLE:
				_double = strtod( input.c_str(), NULL );
		}
		return false ;
	}
	catch (std::exception &e){
		return true ;
	}
}

void	Converter::_convertValue( void )
{
	switch ( _type ){
		case CHAR:
			_int = static_cast< int >(_char);
			_float = static_cast< float >(_char);
			_double = static_cast< double >(_char);
			break ;
		case INT:
			_char = static_cast< char >(_int);
			_float = static_cast< float >(_int);
			_double = static_cast< double >(_int);
			break ;
		case FLOAT:
			_char = static_cast< char >(_float);
			_int = static_cast< int >(_float);
			_double = static_cast< double >(_float);
			break ;
		case DOUBLE:
			_char = static_cast< char >(_double);
			_int = static_cast< int >(_double);
			_float = static_cast< float >(_double);
	}
}

void	Converter::_printChar( void )
{
	std::cout << "char: ";
	if ( _int > 0 && _int < 128 ){
		if ( isprint(_int) )
			std::cout << _char;
		else
			std::cout << "non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::_printInt( void )
{
	std::cout << "integer: ";
	if ( static_cast< double >( std::numeric_limits< int >::min() ) <= _double
			&& static_cast< double >( std::numeric_limits< int >::max() ) >= _double )
		std::cout << _int;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::_printFloat( std::string const &input )
{
	std::cout << "float: ";
	if ( !_pseudo_literal && -std::numeric_limits< float >::max() <= _double
		&& std::numeric_limits< float >::max() >=_double ){
		std::cout << _float;
	}
	else
		if ( input == "+inff" || input == "+inf" )
			std::cout << "+inf";
		else if ( input == "-inff" || input == "-inf" )
			std::cout << "-inf";
		else
			std::cout << "nan";
	std::cout << "f" << std::endl;
}

void	Converter::_printDouble( std::string const &input )
{
	std::cout << "double: ";
	if ( _pseudo_literal ){
		if ( input == "+inff" || input == "+inf" )
			std::cout << "+inff";
		else if ( input == "-inff" || input == "-inf" )
			std::cout << "-inff";
		else
			std::cout << "nan";
	}
	else
		std::cout << _double;
	std::cout << std::endl;
}

void	Converter::_printConversion( std::string const &input )
{
	if (!_possible || _pseudo_literal){
		std::cout << "char: impossible" << std::endl
		<< "integer: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
		return ;
	}
	_printChar();
	_printInt();
	_printFloat( input );
	_printDouble( input );
}

void	Converter::convert( std::string const &input )
{
	if(input.empty())
	{
		_possible = false;
		_printConversion( input );
		return ;
	}
	static bool	(*funct[4])( std::string const &) = {
		_isChar,
		_isInt,
		_isFloat,
		_isDouble
	};

	for ( _type = 0 ; _type < 4; _type++ ){
		if (funct[_type](input))
			break ;
	}
	if ( _type == 4 || _isImpossible( input ))
		_possible = false ;
	_convertValue();
	_printConversion( input );
}

char	Converter::_char = 0;
int		Converter::_int = 0;
float	Converter::_float = 0.0f;
double	Converter::_double = 0.0;
int		Converter::_type = 0;
bool	Converter::_possible =	true;
bool	Converter::_pseudo_literal = false;