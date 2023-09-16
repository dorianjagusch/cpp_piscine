/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timePmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:50:22 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 10:59:44 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::setStart( void ){
	_startTime = clock();
}

void PmergeMe::setDuration( void ){
	clock_t stop = clock();
	_duration = static_cast<double>(stop - _startTime) / CLOCKS_PER_SEC;
}

double PmergeMe::getDuration( void ){
	return _duration;
}
