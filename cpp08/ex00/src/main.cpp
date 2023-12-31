/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:03:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 12:46:36 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include "string"
#include <cassert>
#include <list>
#include <queue>
#include <map>

int main(void)
{
	try {
		std::vector<int> vector;
		for (int i = 0; i < 50; i+=2){
			vector.push_back(i);
		}
		std::vector<int>::const_iterator result = easyfind(vector, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector(42): " << e.what() << std::endl;
	}
	try {
		std::vector<int> vector;
		for (int i = 0; i < 50; i+=2){
			vector.push_back(i);
		}
		std::vector<int>::const_iterator result = easyfind(vector, 43);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector(43): " << e.what() << std::endl;
	}
	try {
		std::list<int> list;
		for (int i = 0; i < 50; i+=2){
			list.push_back(i);
		}
		std::list<int>::const_iterator result = easyfind(list, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "list(42): " << e.what() << std::endl;
	}
	try {
		std::list<const int> list;
		for (int i = 0; i < 50; i+=2){
			list.push_back(i);
		}
		std::list<const int>::const_iterator result = easyfind(list, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "list(42): " << e.what() << std::endl;
	}
	try {
		std::vector<double> vector;
		for (int i = 0; i < 50; i+=2){
			vector.push_back(i);
		}
		std::vector<double>::const_iterator result = easyfind(vector, 43);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector<double>(42): " << e.what() << std::endl;
	}
	try {
		std::vector<char> vector;
		for (char i = 0; i < 50; i+=2){
			vector.push_back(i);
		}
		std::vector<char>::const_iterator result = easyfind(vector, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector<char>(42): " << e.what() << std::endl;
	}
	try {
		std::vector<long> vector;
		std::vector<long>::const_iterator result = easyfind(vector, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector<long>(42): " << e.what() << std::endl;
	}
	try {
		std::vector<int> vector;
		std::vector<int>::const_iterator result = easyfind(vector, 42);
		std::cout << *result << " found" << std::endl;
	} catch ( std::exception & e ) {
		std::cout << "vector(42) uninitialised: " << e.what() << std::endl;
	}
	return 0;
}