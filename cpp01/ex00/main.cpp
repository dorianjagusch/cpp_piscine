/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:24:32 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/21 14:44:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

int main( void )
{
	Zombie zombie1("Bob");
	Zombie *zombie2 = newZombie("Fred");

	zombie1.announce();
	zombie2->announce();
	randomChump("Steve");
	delete zombie2;
	return (0);
}