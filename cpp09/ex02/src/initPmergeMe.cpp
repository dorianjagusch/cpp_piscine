/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initPmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:09:33 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/21 15:32:39 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::issign( char const c){
	if (c == '+')
		return true;
	return false;
}

PmergeMe::error_codes PmergeMe::validateInput( int ac, char **args ){
	for( int i = 1; i < ac; i++ ){
		int sign_flag = 0;
		for( size_t j = 0; j < std::strlen( args[i] ); j++){
			if ( issign( args[i][j] ) )
				sign_flag++;
			if ( ( !isdigit( args[i][j] ) && !issign( args[i][j] ) ) || sign_flag > 1)
				return invalidErr;
		}
	}
	return good;
}

void	PmergeMe::isIntOverflow( std::string const & str ) throw ( OverFlowException ){

	long long val = atol( str.c_str() ); 
	if ( val >= std::numeric_limits<int>::max() ||
		val <= std::numeric_limits<int>::min() )
		throw ( OverFlowException() );
}

int PmergeMe::makeInt( char const *str ){
	isIntOverflow( str );
	return ( static_cast<int>( atol(str) ) );
}

void PmergeMe::fillVector( int ac, char **args )
{
	int	i = 1;
	int	val;

	try{
		for(; i < ac; i++ ){
			val = makeInt( args[i] );
			_container1.push_back( val );
		}
	} catch (std::exception & e){
		std::cerr << e.what() << " at " << args[i] << std::endl;
		exit(2);
	}
}

void PmergeMe::fillList( int ac, char **args )
{
	int	i = 1;
	int	val;

	try{
		for(; i < ac; i++ ){
			val = makeInt( args[i] );
			_container2.push_back( val );
		}
	} catch (std::exception & e){
		std::cerr << e.what() << args[i] << std::endl;
		exit(2);
	}
}