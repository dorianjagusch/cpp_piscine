/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:21:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 23:07:58 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "ScavTrap.hpp"

int main(void){

	{
		ScavTrap scavvy("Steve");

		scavvy.attack("the great, blue sea");
		scavvy.takeDamage(2);
		scavvy.attack("the dark, green forest");
		scavvy.takeDamage(3);
		scavvy.beRepaired(20);
		scavvy.attack("the hot, sweltering dessert");
		scavvy.takeDamage(5);
		scavvy.attack("the icy, white glaciers");
		scavvy.takeDamage(10);
		scavvy.guardGate();
		scavvy.attack("the infinite, impenetrable void");
		scavvy.takeDamage(std::numeric_limits<unsigned int>::max());
		scavvy.beRepaired(20);
		scavvy.attack("hinmself");
		scavvy.takeDamage(20);
		scavvy.guardGate();
	}
	{
		ScavTrap scavvy("Bobby");

		scavvy.attack("the great, blue sea");
		scavvy.takeDamage(50);
		scavvy.attack("the dark, green forest");
		scavvy.takeDamage(30);
		scavvy.attack("the hot, sweltering dessert");
		scavvy.takeDamage(50);
		scavvy.attack("the icy, white glaciers");
		scavvy.takeDamage(100);
		scavvy.attack("the infinite, impenetrable void");
		scavvy.takeDamage(std::numeric_limits<unsigned int>::max());
		scavvy.guardGate();
	}
	{
		ScavTrap scavvy("Zeus");
		for (int i = 0; i < 30; i++)
		{
			scavvy.attack("the great, blue sea");
			scavvy.takeDamage(2);
			scavvy.attack("the dark, green forest");
			scavvy.takeDamage(2);
			scavvy.beRepaired(10);
			scavvy.attack("the hot, sweltering dessert");
			scavvy.takeDamage(2);
			scavvy.attack("the icy, white glaciers");
			scavvy.takeDamage(2);
			scavvy.attack("the infinite, impenetrable void");
			scavvy.guardGate();
		}
		scavvy.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	return (0);
}