/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:00:08 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:36 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<long> RPN::_stack;

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
		if ( isspace( str[i] ) )
			continue;
		n_words++;
		while ( i < str.length() && !isspace( str[i] ) )
			i++;
	}
	return n_words;
}

std::string* RPN::split( const std::string& str, size_t num ) {

	if ( num < 3 ) return NULL;
	
	std::string* 		tokens = new std::string[num + 1];
	std::istringstream	stream(str);
	std::string			token;
	size_t				current = 0;


	while ( std::getline(stream, token, ' ') ) {
		if ( !token.empty() )
			tokens[current++] = (token);
	}
	return (tokens);
}
bool RPN::isoperation( char const c ){
	
	if (c == '+' || c == '-'
		|| c == '*' || c == '/')
		return true;
	return false;
}

long long RPN::add(long long const a, long long const b) throw ( OverflowException ){
	
	if ( a + b > std::numeric_limits<long>::max()
		|| a+ b < std::numeric_limits<long>::min())
		throw ( OverflowException() );
	return a + b;
}
	
long long RPN::sub(long long const a, long long const b) throw ( OverflowException ) {
	
	if ( a - b < std::numeric_limits<long>::min()
		||  a - b > std::numeric_limits<long>::max() )
		throw ( OverflowException() );
	return a - b;
}

long long RPN::mult(long long const a, long long const b) throw ( OverflowException ) { 

	long res = static_cast<long>(a * b);
	if ( res % a != 0 || res % b != 0 )
		throw ( OverflowException() );
	return a * b ;
}

long long RPN::div(long long const a, long long const b) throw ( DivideByZeroException ) { 
	if ( b == 0 )
		throw ( DivideByZeroException() );
	return a / b ;
} 

void RPN::do_op( char op )
{
	long long top, bottom, res;
	top = _stack.top();
	_stack.pop();
	bottom = _stack.top();
	_stack.pop();
	switch (op){
		case '+':
			res = add( top , bottom );
			break;
		case '-':
			res = sub( bottom , top );
			break;
		case '*':
			res = mult( top , bottom );
			break;
		case '/':
			res = div( bottom , top );
			break;
	}
	_stack.push(static_cast<long>(res));
}


void	RPN::calcResult( std::string *split_expr, size_t num){
	int	op_flag = 2;
	int	num_flag = 0;
	long long tmp;
	int op;
	for ( size_t i = 0; i < num; i++ ){
		if ( isdigit( split_expr[i][0] ) && num_flag < 2){
			num_flag++;
			op_flag = 0;
			tmp = atol( split_expr[i].c_str() );
				if (tmp > std::numeric_limits<long>::max()
					|| tmp < std::numeric_limits<long>::min())
					throw ( OverflowException() );
			_stack.push( tmp );
		}
		else if ( (op = isoperation( split_expr[i][0] ) ) && num_flag == 2 ){
			num_flag = 1;
			op_flag++;
			do_op( split_expr[i][0] );
		}
		if (op_flag > 1 || num_flag > 2){
			std::cerr << "Error: wrong format for reverse Polish notation" << std::endl;
			return ;// exit( 5 );
		}
	}
}



void RPN::DoTheThing(std::string expr){

	
	for (size_t i = 0; i < expr.size(); i++)
	{
		if ( !isspace( expr[i] )
			&& !isdigit( expr[i] )
			&& !isoperation( expr[i] ) ){
			std::cerr << "Error: invalid character: " << expr[i] << std::endl;
			return ;// exit( 2 );
		}
	}
	size_t num = count_words(expr);
	std::string* split_expr = split(expr, num);
	if ( !split_expr || split_expr[0].empty()){
		std::cerr << "Error: wrong format for reverse Polish notation" << std::endl;
		return ;// exit(3) ;
	}
	try{
		calcResult(split_expr, num);
	}
	catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
				return ;//exit( 5 );
	}
	if (!_stack.empty())
		std::cout << _stack.top() << std::endl;
	while (!_stack.empty())
		_stack.pop();
}
