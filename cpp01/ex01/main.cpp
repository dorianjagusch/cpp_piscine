/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:24:32 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <limits>

Zombie *zombieHorde( int N, std::string name );

int main( void )
{
	int n = 10;
	Zombie *horde = zombieHorde( n, "JAAAAAAAAASSOOOOOON" );
	if ( horde ) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;

	n = 1;
	horde = zombieHorde( 1, "Captain Crunch" );
	if ( horde ) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;

	n = -24;
	horde = zombieHorde( n, "Lapras" );
	if ( horde ) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;

	n = std::numeric_limits<int>::max() + 1;
	horde = zombieHorde(n, "John Snow");
	if (horde) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;

	n = std::numeric_limits<int>::min() - 1;
	horde = zombieHorde( n, "Boaty McBoatface" );
	if ( horde ) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;

	n = 0;
	horde = zombieHorde( n, "Zero" );
	if ( horde ) {
		for ( int i = 0; i < n; i++ ){
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << "==================================" << std::endl;
	return 0;
}