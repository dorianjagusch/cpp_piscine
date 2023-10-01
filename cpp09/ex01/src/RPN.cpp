/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:00:08 by djagusch          #+#    #+#             */
/*   Updated: 2023/10/01 20:32:39 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<long> RPN::_stack;

char const * RPN::OverflowException::what( void ) const throw(){
	return ( "Exception: Result overflowed long type" );
}
char const * RPN::DivideByZeroException::what( void ) const throw(){
	return ( "Exception: Division by zero" );
}

RPN::RPN()
{}

RPN::RPN( RPN const & src )
{
	*this = src;
}

RPN::~RPN()
{}

RPN &	RPN::operator=( RPN const & rhs )
{
	if( this != &rhs )
		_stack = rhs._stack;
	return (*this);
}

size_t	RPN::count_words( std::string str ){

	size_t n_words = 0;
	size_t i = 0;

	while ( isspace( str[i] ) )
		i++;
	for ( ; i < str.length(); i++ ){
		if ( isspace( str[i] ) )
			continue;
		n_words++;
		while ( i < str.length() && !isspace( str[i] ) )
			i++;
	}
	return n_words;
}

std::string* RPN::split( const std::string& str, size_t num ) {

	std::string* 		tokens = new std::string[num];
	std::istringstream	stream(str);
	std::string			token;
	size_t				current = 0;

	while ( std::getline( stream, token, ' ' ) ) {
		if ( !token.empty() )
		{
			if ( CheckArgument( token ) )
				tokens[current++] = token;
			else{
				delete [] tokens;
				exit( 3 );
			}
		}
	}
	return (tokens);
}

void	RPN::calcResult( std::string *split_expr, size_t num ){

	int	op_flag = 2;
	int	num_flag = 0;
	long long tmp;
	int op;
	for ( size_t i = 0; i < num; i++ ){
		if ( isdigit( split_expr[i][0] )
			|| ( ( split_expr[i][0] == '+' || split_expr[i][0] == '-' )
				&& isdigit( split_expr[i][1] ) ) ){
			num_flag++;
			op_flag--;
			if ( isLongOverflow( split_expr[i] ) )
				throw ( OverflowException() );
			tmp = atol( split_expr[i].c_str() );
			_stack.push( tmp );
		}
		else if ( ( op = isoperation( split_expr[i] ) ) && num_flag >= 2
			&& op_flag <= ( num_flag - 2 ) ){
			num_flag--;
			op_flag++;
			do_op( split_expr[i][0] );
		}
		else {
			std::cerr << "Error: wrong format for reverse Polish notation" << std::endl;
			exit( 5 );
		}
	}
	if ( op_flag <= 0 ){
		std::cerr << "Error: missing operator" << std::endl;
		ClearAllocs( split_expr );
		exit( 6 );
	}
}

void RPN::ClearAllocs( std::string* split_expr ){

	while ( !_stack.empty() )
		_stack.pop();
	if ( split_expr )
		delete [] split_expr;

}

void RPN::DoTheThing( std::string expr ){

	CheckCharacters( expr );
	size_t num = count_words( expr );
	std::string* split_expr = split( expr, num );
	if ( !split_expr || split_expr[0].empty() ){
		std::cerr << "Error: wrong format for reverse Polish notation" << std::endl;
		exit( 4 ) ;
	}
	if ( num == 1 && !isLongOverflow( split_expr[0] )
		&& ( isdigit( split_expr[0][0] ) || isdigit( split_expr[0][1] ) ) ){
		std::cout << split_expr[0] << std::endl;
		ClearAllocs( split_expr );
		return ;
	}
	try{
		calcResult( split_expr, num );
	}
	catch ( std::exception & e ) {
		std::cerr << e.what() << std::endl;
		ClearAllocs( split_expr );
		exit( 7 );
	}
	if ( !_stack.empty() )
		std::cout << _stack.top() << std::endl;
	ClearAllocs( split_expr );
}
