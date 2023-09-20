/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:47 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/19 15:36:57 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	std::cout << std::boolalpha;
	{
		std::cout << "================ In triangle =================" << std::endl;
		Point a(0, 2);
		Point b(2, 2);
		Point c(0, -5);
		Point array[] = {
			Point(0, 0),
			Point(0, 1),
			Point(0.2, 1),
			Point(0.3, 1),
			Point(0.5, 1)
		};

		std::cout << "Triangle: " << std::endl
				<< "a: " << a << std::endl
				<< "b: " << b << std::endl
				<< "c: " << c << std::endl
				<< "------------------------------" << std::endl;

		for (size_t i = 0; i < sizeof(array) / sizeof(Point); i++){
			std::cout	<< "Point: " << array[i] << " in Triangle?\t"
						 << bsp(a, b, c, array[i]) << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "================ Out of triangle =================" << std::endl;
		Point a(5, 2);
		Point b(5, 3);
		Point c(4, 5);
		Point array[] = {
			Point(0, 0),
			Point(0, 1),
			Point(0.2, 1),
			Point(0.3, 1),
			Point(0.5, 1)
		};

		std::cout << "Triangle: " << std::endl
			<< "a: " << a << std::endl
			<< "b: " << b << std::endl
			<< "c: " << c << std::endl
			<< "------------------------------" << std::endl;;

		for (size_t i = 0; i < sizeof(array) / sizeof(Point); i++){
			std::cout	<< "Point: " << array[i] << " in Triangle?\t"
						 << bsp(a, b, c, array[i]) << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "================ On triangle edge =================" << std::endl;
		Point a(0, 0);
		Point b(0, 3);
		Point c(3, 3);
		Point array[] = {
			a,
			b,
			c,
			Point(1, 2)
		};

		std::cout << "Triangle: " << std::endl
			<< "a: " << a << std::endl
			<< "b: " << b << std::endl
			<< "c: " << c << std::endl
			<< "------------------------------" << std::endl;;

		for (size_t i = 0; i < sizeof(array) / sizeof(Point); i++){
			std::cout	<< "Point: " << array[i] << " in Triangle?\t"
						 << bsp(a, b, c, array[i]) << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}