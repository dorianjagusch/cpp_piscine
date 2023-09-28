/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:11:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/28 10:49:51 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double					PmergeMe::_startTime;
double					PmergeMe::_duration1;
double					PmergeMe::_duration2;
std::vector<long long>	PmergeMe::_container1;
std::list<long long>	PmergeMe::_container2;

const char *PmergeMe::OverFlowException::what( void ) const throw() {
	return "Exception: Overflow occured";
}

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( int ac, char **args )
{
	if ( validateInput( ac, args ) ) {
		std::cerr << "Error: Invalid input: provide positive integers as individual arguments" << std::endl;
		exit(2);
	};
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
	return *this;
}

PmergeMe::~PmergeMe()
{}

std::vector<long long> PmergeMe::getContainer( void ) const {
	return _container1;
}

bool PmergeMe::is_sort( std::list<long long>::iterator begin, std::list<long long>::iterator end )
{
	std::list<long long>::iterator it, it2;
	
	it = it2 = begin;
	it2++;
	for (; it2 != end; it++, it2++)
	{
		if (*it > *it2)
			return false;
	}
	return true;
}

bool PmergeMe::is_sort( std::vector<long long>::iterator begin, std::vector<long long>::iterator end )
{
	std::vector<long long>::iterator it, it2;
	
	it = it2 = begin;
	it2++;
	for (; it2 != end; it++, it2++)
	{
		if (*it > *it2)
			return false;
	}
	return true;
}

void PmergeMe::sort( int ac, char **av ){
	
	{
		setStart();
		fillVector( ac, av );
		std::cout << "Before:\t";
		printContainer( _container1 );
		std::vector<long long>::iterator beg = _container1.begin();
		std::vector<long long>::iterator end = _container1.end();
		sortContainer( beg, end );
		// std::cout << is_sort( beg, end ) << std::endl;
		setDuration( _duration1 );
	}

	{
		setStart();
		fillList( ac, av );
		std::list<long long>::iterator beg = _container2.begin();
		std::list<long long>::iterator end = _container2.end();
		sortContainer( beg, end );
		// std::cout << is_sort( beg, end ) << std::endl;
		std::cout << "After:\t";
		printContainer( _container2 );
		setDuration( _duration2 );
	}
	printResult( _container1 , _duration1, VECTOR_TYPE );
	printResult( _container2 , _duration2, LIST_TYPE );
}