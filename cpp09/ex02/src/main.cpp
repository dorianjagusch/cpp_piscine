/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/21 15:05:42 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <list>
#include <algorithm>

int main(int ac, char **av)
{
	if (ac == 1){
		std::cerr << "Provide a sequence of integers separated by spaces please" << std::endl;
		return 1;
	}
	try{
		PmergeMe toSort( ac, av );
			toSort.sort( ac, av );
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}