/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:23:05 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/28 09:20:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define S_LONG_MIN "-9223372036854775808"
#define S_LONG_MAX "9223372036854775807"

bool	RPN::isLongOverflow( std::string const & str){
	long val = atol( str.c_str() ); 
	
	if ( val != std::numeric_limits<long>::max() &&
		val != std::numeric_limits<long>::min() )
		return true;
	if ( std::strcmp (str.c_str(), S_LONG_MAX ) == 0
		|| std::strcmp( str.c_str(), S_LONG_MIN ) == 0 ) {
		return false;
	}
	return true;
}

void RPN::CheckCharacters( std::string & expr ){
		for (size_t i = 0; i < expr.size(); i++)
	{
		if ( !isspace( expr[i] )
			&& !isdigit( expr[i] )
			&& !isoperation( expr[i] ) ){
			std::cerr << "Error: invalid character: " << expr[i] << std::endl;
			exit( 2 );
		}
	}
}

bool RPN::CheckArgument( std::string const expr ){

	if ( isoperation( expr ) ){
		return true;
	}
	int sign_flag = 0;
	for ( size_t i = 0; i < expr.size(); i++) {
		if ( expr[i] == '+' || expr[i] ==  '-' )
			sign_flag++;
		if ( !isdigit( expr[i] ) && expr[i] != '+' && expr[i] !=  '-' && sign_flag > 1 ){
			std::cerr << "Error: " << expr << " requires space between numbers and operators" << std::endl;
			return false;
		}
	}
	return true;
}
