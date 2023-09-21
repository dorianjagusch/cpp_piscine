/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecSortPmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:18 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/21 16:06:18 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::merge( std::vector<long long>::iterator beg, std::vector<long long>::iterator mid,
	std::vector<long long>::iterator end )
{
	std::vector<long long> temp( static_cast<unsigned long>( end - beg ) );
	std::vector<long long>::iterator temp_it = temp.begin();

	std::vector<long long>::iterator beg1 = beg;
	std::vector<long long>::iterator beg2 = mid;

	while ( beg1 != mid && beg2 != end ) {
		if ( *beg1 <= *beg2 ) {
			*temp_it = *beg1;
			beg1++;
		} else {
			*temp_it = *beg2;
			beg2++;
		}
		temp_it++;
	}

	while ( beg1 != mid ) {
		*temp_it = *beg1;
		beg1++;
		temp_it++;
	}

	while ( beg2 != end ) {
		*temp_it = *beg2;
		beg2++;
		temp_it++;
	}
	
	std::copy( temp.begin(), temp.end(), beg );
}

void PmergeMe::insertion_sort( std::vector<long long>::iterator beg , std::vector<long long>::iterator end )
{
	std::vector<long long>::iterator it1;
	std::vector<long long>::iterator it2;

	for ( it1 = beg; it1 != end - 1; it1++ ){
		it2 = it1 + 1;
		while ( it2 != beg && *(it2 - 1) > *it2 ) {
			std::iter_swap(it2, it2 - 1);
			it2--;
		}
	}
}

void PmergeMe::sortContainer( std::vector<long long>::iterator beg, std::vector<long long>::iterator end ){
	long distance = std::distance(beg, end) - 1;

	if ( distance > MIN_SIZE )
	{
		long half_dist = distance / 2 ;
		std::vector<long long>::iterator mid = beg + half_dist + 1;
		sortContainer( beg, mid );
		sortContainer( mid, end );
		merge( beg, mid, end );
	} else {
		insertion_sort( beg, end );
	}
}
