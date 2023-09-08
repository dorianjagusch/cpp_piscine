/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:53:57 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/08 13:52:45 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>


int main(void)
{
	{
		std::cout << "============== Subject example =============" << std::endl << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "============== Large span (100k) =============" << std::endl << std::endl;
		std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
		Span sp = Span( 10000 );

		for ( int i = 0; i < 10000; i++ ){
			sp.addNumber( std::rand() );
		}
		// std::cout << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;

		std::cout << "============== Large span (10k) =============" << std::endl << std::endl;
		std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
		Span sp2 = Span( 10000 );
		sp2.addNumber( sp.getList().begin(), sp.getList().end() );
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl << std::endl;

		std::cout << "============== Add range of numbers =============" << std::endl << std::endl;

		std::pair <std::list<int>::const_iterator, std::list<int>::const_iterator > iter(sp.getList().begin(), sp2.getList().begin());
		for ( ; iter.first != sp.getList().end() && iter.second != sp2.getList().end(); iter.first++, iter.second++ ){
			if ( *iter.first != *iter.second ){
				std::cout << "Not the same" << std::endl;
				return (1);
			}
		}
		std::cout << "Arrays are the same. Success!" << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl << std::endl;
	}
	return 0;
}
