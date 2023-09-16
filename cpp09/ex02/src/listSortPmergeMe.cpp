/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listSortPmergeMe.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:18 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 13:07:49 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::merge(std::list<long long>::iterator beg, std::list<long long>::iterator mid,
	std::list<long long>::iterator end)
{
	std::list<long long>::iterator beg1 = beg;
	std::list<long long>::iterator beg2 = std::next( mid );
	std::list<long long>::iterator mid2 = beg2 ;

	std::vector<long long> temp(static_cast<unsigned long>( std::distance( beg, end ) ) );
	std::vector<long long>::iterator temp_it = temp.begin();
	
	while ( beg1 != mid2 && beg2 != end ){
		if (*beg1 <= *beg2 ){
			*temp_it = *beg1;
			beg1++;
		} else {
			*temp_it = *beg2;
			beg2++;
		}
		temp_it++;
	}
		
	while(beg1 != mid2){
		*temp_it = *beg1;
		temp_it++;
		beg1++;
	}
	
	while(beg2 != end){
		*temp_it = *beg2;
		temp_it++;
		beg2++;
	}
	std::copy(temp.begin(), temp.end(), beg);
}

void PmergeMe::insertion_sort( std::list<long long>::iterator beg , std::list<long long>::iterator end )
{
	std::list<long long>::iterator it1;
	std::list<long long>::iterator it2 = it1;
	std::list<long long>::iterator temp;
	
	for ( it1 = beg; it1 != end ; it1++ ){
		it2 = it1;
		temp = it2;
		std::next( it2 );
		while ( it2 != end && *temp > *it2 ){
			iter_swap( it2, temp );
			prev( it2 );
			prev( temp );
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
		std::list<long long>::iterator mid2 = mid;
		next( mid2 );
		sortContainer( mid2, end );
		merge( beg, mid, end );
	} else {
		insertion_sort( beg, end );
	}
}

