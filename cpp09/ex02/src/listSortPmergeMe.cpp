/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listSortPmergeMe.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:18 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/21 16:07:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::merge( std::list<long long>::iterator beg, std::list<long long>::iterator mid,
	std::list<long long>::iterator end )
{
	std::list<long long>::iterator beg1 = beg;
	std::list<long long>::iterator beg2 = mid;

	std::vector<long long> temp( static_cast<unsigned long>( std::distance( beg, end ) ) );
	std::vector<long long>::iterator temp_it = temp.begin();

	while ( beg1 != mid && beg2 != end ){
		if ( *beg1 <= *beg2 ){
			*temp_it = *beg1;
			beg1++;
		} else {
			*temp_it = *beg2;
			beg2++;
		}
		temp_it++;
	}
		
	while( beg1 != mid ){
		*temp_it = *beg1;
		temp_it++;
		beg1++;
	}
	
	while( beg2 != end ){
		*temp_it = *beg2;
		temp_it++;
		beg2++;
	}
	std::copy( temp.begin(), temp.end(), beg );
}

void PmergeMe::insertion_sort( std::list<long long>::iterator beg , std::list<long long>::iterator end )
{
	std::list<long long>::iterator it1;
	std::list<long long>::iterator it2;
	std::list<long long>::iterator temp;
	std::list<long long>::iterator end2 = end;
	end2--;

	for ( it1 = beg; it1 != end2 ; it1++ ){
		it2 = temp = it1;
		it2++;
		while ( it2 != beg && *temp > *it2 ){
			std::iter_swap( it2, temp );
			it2--;
			temp--;
		}
	}
}

void PmergeMe::sortContainer( std::list<long long>::iterator beg, std::list<long long>::iterator end ){
	long distance = std::distance(beg, end) - 1;

	if ( distance > MIN_SIZE )
	{
		long half_dist = distance / 2 ;
		std::list<long long>::iterator mid = beg;
		std::advance( mid, half_dist + 1);
		sortContainer( beg, mid );
		sortContainer( mid, end );
		merge( beg, mid, end );
	} else {
		insertion_sort( beg, end );
	}
}
