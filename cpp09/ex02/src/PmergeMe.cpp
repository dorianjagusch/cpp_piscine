/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:11:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 13:12:17 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double					PmergeMe::_startTime;
double					PmergeMe::_duration;
std::vector<long long>	PmergeMe::_container1;
std::list<long long>	PmergeMe::_container2;

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( int ac, char **args )
{
	if ( validateInput( ac, args ) ) {
		std::cerr << "Error: Invalid input: provide positive integers as individual arguments" << std::endl;
		exit( 2 );
	};
	fillContainers( ac, args );
}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	*this = src; 
}

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs )
{
	if( this != &rhs )
		_container1 = rhs._container1;
		_container2 = rhs._container2;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

std::vector<long long> PmergeMe::getContainer( void ) const {
	return (_container1);
}

void PmergeMe::sort( void ){
	
	std::cout << "Before: ";
	printContainer( _container1 );
	{
		setStart();
		std::vector<long long>::iterator beg = _container1.begin();
		std::vector<long long>::iterator end = _container1.end();
		sortContainer( beg, end );
		setDuration();
		std::cout << "After: ";
		printContainer( _container1 );
		printResult( _container1 , _duration, VECTOR_TYPE );
	}
	{
		setStart();
		std::list<long long>::iterator beg = _container2.begin();
		std::list<long long>::iterator end = _container2.end();
		sortContainer( beg, end );
		setDuration();
		printResult( _container2 , _duration, LIST_TYPE );
	}
}