/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:11:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/13 15:45:03 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <cstdlib>


class RPN
{
public:
	RPN ();
	RPN( RPN const & src );
	~RPN();

	RPN &	operator=( RPN const & rhs );

private:
	static std::stack<long>	_stack;
	static std::string*	split( const std::string& str, size_t num );
	static bool			isoperation( char const c );
	static size_t		count_words( std::string str );
	static void			checkIput( std::string expr );
	static long			do_op( char op );
	static long			add( long a, long b );
	static long			sub( long a, long b );
	static long			mult( long a, long b );
	static long			div( long a, long b );
};

std::stack<long>	RPN::_stack;

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
	
	while (isspace( str[i] ))
		i++;
	for ( ; i < str.length(); i++ ){
		if ( isspace( str[i] ) ){
			n_words++;
			while (isspace( str[i] ))
				i++;
		}
	}
	return n_words;
}

std::string* RPN::split( const std::string& str, size_t num ) {

	std::string* 		tokens = new std::string[num];
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
bool RPN::isoperation( char const c ){
	
	if (c == '+' || c == '-'
		|| c == '*' || c == '/')
		return true;
	return false;
}

long RPN::add(long a, long b){ a + b;}
long RPN::sub(long a, long b){ a - b;}
long RPN::mult(long a, long b){ a * b ;}
long RPN::div(long a, long b){ b != 0 ? a / b : 0 ;} // fix

long RPN::do_op( char op )
{
	long a, b, res;
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	switch (op){
		case '+':
			res = add( a , b );
			break;
		case '-':
			res = sub( a , b );
			break;
		case '*':
			res = mult( a , b );
			break;
		case '/':
			res = div( a , b );
			break;
	}
	_stack.push(res);
}

void RPN::checkIput(std::string expr){
	
	for (size_t i = 0; i < expr.size(); i++)
	{
		if ( !isspace( expr[i] )
			&& !isdigit( expr[i] )
			&& !isoperation( expr[i] ) )
			std::cerr << "Error: invalid character: " << expr[i] << std::endl;
	}
	size_t num = count_words(expr);
	std::string* split_expr = split(expr, num);
	int	op_flag = 0;
	int	num_flag = 0;
	long a, b;
	for ( size_t i = 0; i < num; i++ ){
		if ( isdigit( split_expr[i][0] ) && num_flag < 2 && op_flag = 0){
			num_flag++;
			op_flag = 0;
			_stack.push( atol( split_expr[i].c_str() ) );
		}
		else if ( isoperation( split_expr[i][0] ) && num_flag == 2 ){
			num_flag = 1;
			do_op( split_expr[i][0] );
		}
		if (op_flag > 1 || num_flag > 2){
			std::cerr << "Error: wrong format for reverse Polish notation" << std::endl;
			exit (1);
		}
	}
	
}

#endif