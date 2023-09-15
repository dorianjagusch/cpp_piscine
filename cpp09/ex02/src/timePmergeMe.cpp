/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timePmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:50:22 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 19:16:21 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::setStart( int flag ){
	static const std::string conts[3] = {
		"std::vector<int>",
		"std::list<int>"
	};

	std::cout << "Time to process a range of\t"
		<< _container1.size()
		<< " elements with " << conts[flag] << ":\t";
	_startTime = clock();
}

void PmergeMe::printDuration( void ){
	clock_t stop = clock();
	double duration = static_cast<double>(stop - _startTime) / CLOCKS_PER_SEC;
	std::cout << duration << std::endl;
}