/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:01:47 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 17:45:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed z( 25 );
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
	
	Fixed const f( Fixed( 5.05f ) + Fixed( -2 ) );
	Fixed const g( Fixed( 5.05f ) - Fixed( -2 ) );
	Fixed const h( Fixed( 5.05f ) * Fixed( -2 ) );
	Fixed const i( Fixed( 5.05f ) / Fixed( -2 ) );
	
	Fixed const j( Fixed( -5.05f ) + Fixed( 2 ) );
	Fixed const k( Fixed( -5.05f ) - Fixed( 2 ) );
	Fixed const l( Fixed( -5.05f ) * Fixed( 2 ) );
	Fixed const m( Fixed( -5.05f ) / Fixed( 2 ) );

	Fixed const n( Fixed( -5.05f ) + Fixed( -2 ) );
	Fixed const o( Fixed( -5.05f ) - Fixed( -2 ) );
	Fixed const p( Fixed( -5.05f ) * Fixed( -2 ) );
	Fixed const q( Fixed( -5.05f ) / Fixed( -2 ) );
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << std::endl;
	std::cout << "h: " << h << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "k: " << k << std::endl;
	std::cout << "l: " << l << std::endl;
	std::cout << "m: " << m << std::endl;
	std::cout << "n: " << n << std::endl;
	std::cout << "o: " << o << std::endl;
	std::cout << "p: " << p << std::endl;
	std::cout << "q: " << q << std::endl;

	std::cout << "current a: " << a << std::endl;
	std::cout << "preincr a: "<< ++a << std::endl;
	std::cout << "current a: " << a << std::endl;
	std::cout << "postincr a: "<< a++ << std::endl;
	std::cout << "current a: " << a << std::endl;
	std::cout << "current a: " << a << std::endl;
	std::cout << "predecr a: "<< --a << std::endl;
	std::cout << "current a: " << a << std::endl;
	std::cout << "postdecr a: "<< a-- << std::endl;
	std::cout << "current a: " << a << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, z ) << std::endl;
	std::cout << Fixed::min( a, z ) << std::endl;
	return 0;
}