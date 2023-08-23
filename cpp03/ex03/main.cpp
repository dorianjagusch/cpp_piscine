/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:21:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 15:29:57 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "DiamondTrap.hpp"

int main(void){

	{
		DiamondTrap diddy("Steve");

		diddy.attack("the great, blue sea");
		diddy.takeDamage(2);
		diddy.attack("the dark, green forest");
		diddy.takeDamage(3);
		diddy.beRepaired(20);
		diddy.attack("the hot, sweltering dessert");
		diddy.takeDamage(5);
		diddy.attack("the icy, white glaciers");
		diddy.takeDamage(10);
		diddy.HighFiveGuys();
		diddy.attack("the infinite, impenetrable void");
		diddy.takeDamage(std::numeric_limits<unsigned int>::max());
		diddy.beRepaired(20);
		diddy.attack("hinmself");
		diddy.takeDamage(20);
		diddy.HighFiveGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap diddy("Bobby");

		diddy.attack("the great, blue sea");
		diddy.takeDamage(50);
		diddy.attack("the dark, green forest");
		diddy.takeDamage(30);
		diddy.attack("the hot, sweltering dessert");
		diddy.takeDamage(50);
		diddy.attack("the icy, white glaciers");
		diddy.takeDamage(100);
		diddy.attack("the infinite, impenetrable void");
		diddy.takeDamage(std::numeric_limits<unsigned int>::max());
		diddy.guardGate();
	}
	std::cout << std::endl;
	{
		DiamondTrap diddy("Zeus");
		for (int i = 0; i < 4; i++)
		{
			diddy.attack("the great, blue sea");
			diddy.takeDamage(2);
			diddy.attack("the dark, green forest");
			diddy.takeDamage(2);
			diddy.whoAmI();
			diddy.beRepaired(10);
			diddy.attack("the hot, sweltering dessert");
			diddy.takeDamage(2);
			diddy.attack("the icy, white glaciers");
			diddy.takeDamage(2);
			diddy.attack("the infinite, impenetrable void");
		}
		diddy.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	return (0);
}