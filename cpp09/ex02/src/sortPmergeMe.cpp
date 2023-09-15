/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortPmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:18 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 19:13:22 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define VECTOR_TYPE 0
#define LIST_TYPE 1
#define MIN_SIZE 1

template <typename Iterator>
void my_iter_swap( Iterator a, Iterator b ) {
	typename Iterator::value_type temp = *a;
	*a = *b;
	*b = temp;
}

void PmergeMe::merge(std::vector<long long>::iterator beg, std::vector<long long>::iterator mid,
	std::vector<long long>::iterator end, long long max_entry )
{
	std::vector<long long>::iterator beg1 = beg;
	std::vector<long long>::iterator beg2 = mid + 1;
	std::vector<long long>::iterator array_it = beg;
	
	while ( beg1 <= mid && beg2 <= end ){
		if (*beg1 % max_entry <= *beg2 % max_entry ){
			*array_it = *array_it + ( *beg1 % max_entry ) * max_entry;
			array_it++;
			beg1++;
		} else {
			*array_it = *array_it + ( *beg2 % max_entry ) * max_entry;
			array_it++;
			beg2++;
		}
	}
		
	while(beg1 <= mid){
		*array_it = *array_it + ( *beg1 % max_entry ) * max_entry;
		array_it++;
		beg1++;
	}
	
	while(beg2 <= end){
		*array_it = *array_it + ( *beg2 % max_entry ) * max_entry;
		array_it++;
		beg2++;
	}
	for (beg1 = beg; beg1 <= end; beg1++)
	{
		*beg1 = *beg1 / max_entry;
	}
}

void PmergeMe::insertion_sort( std::vector<long long>::iterator beg , std::vector<long long>::iterator end )
{
	std::vector<long long>::iterator it1;
	std::vector<long long>::iterator it2;
	
	for ( it1 = beg; it1 != end; it1++ ){
		it2 = it1 + 1;
		while ( it2 <= end && *( it2 - 1 ) > *it2 ){
			my_iter_swap( it2, it2 - 1 );
			it2--;
		}
	}
}

void PmergeMe::sortContainer( std::vector<long long>::iterator beg, std::vector<long long>::iterator end,
		long long max_entry ){
	long distance = std::distance(beg, end);
	
	if ( distance > MIN_SIZE )
	{
		long half_dist = distance / 2 ;
		std::vector<long long>::iterator mid = beg + half_dist;
		sortContainer(beg, mid, max_entry );
		sortContainer(mid + 1, end, max_entry );
		merge( beg, mid, end, max_entry );
	} else {
		insertion_sort( beg, end );
	}
}

void PmergeMe::sort( void ){
	{
		setStart( VECTOR_TYPE );
		std::vector<long long>::iterator beg = _container1.begin();
		std::vector<long long>::iterator end = --_container1.end();
		long long max_entry = *std::max_element(beg, end);
		sortContainer( beg, end, max_entry );
		printDuration();
	}
	// {
	// 	setStart( LIST_TYPE );
	// 	std::list<long long>::iterator beg = _container2.begin();
	// 	std::list<long long>::iterator end = _container2.end()--;
	// 	long long max_entry = *std::max_element(beg, end);
	// 	sortContainer( _container2, beg, end, max_entry );
	// 	printDuration();
	// }
}