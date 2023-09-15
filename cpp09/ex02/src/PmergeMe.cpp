/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:11:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 19:02:45 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( int ac, char **args )
{
	if ( !validateInput( ac, args ) ) { exit( 2 ); };
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

std::ostream &	PmergeMe::printContainer( std::ostream & o, PmergeMe const & rhs ) const {
	const std::vector<long long> container_cpy = rhs.getContainer();
	std::vector<long long>::const_iterator it;
	
	for ( it =  container_cpy.cbegin(); it != container_cpy.cend(); it++ ){
		o << *it << std::endl;
	}
	return o;
}