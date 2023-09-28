/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:21:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/28 12:00:06 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isoperation( char const c ){

	if (c == '+' || c == '-'
		|| c == '*' || c == '/')
		return true;
	return false;
}

bool RPN::isoperation( std::string const str ){

	if (str == "+" || str == "-"
		|| str == "*" || str == "/")
		return true;
	return false;
}

long long RPN::add(long long const a, long long const b)
	throw ( OverflowException ){

	if ((b > 0 && a > std::numeric_limits<long long>::max() - b) ||
		(b < 0 && a < std::numeric_limits<long long>::min() - b)) {
		throw ( OverflowException() );
		}
	return a + b;
}

long long RPN::sub(long long const a, long long const b)
	throw ( OverflowException ){

	if ((b > 0 && a < std::numeric_limits<long long>::min() + b) ||
		(b < 0 && a > std::numeric_limits<long long>::max() + b))
		throw ( OverflowException() );
	return a - b;
}

long long RPN::mult(long long const a, long long const b)
	throw ( OverflowException ) {

	long res = static_cast<long>(a * b);
	if ( ( a != 0 && res % a != 0 ) || (b != 0 && res % b != 0 ) )
		throw ( OverflowException() );
	return a * b ;
}

long long RPN::div(long long const a, long long const b)
	throw ( DivideByZeroException ) {
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