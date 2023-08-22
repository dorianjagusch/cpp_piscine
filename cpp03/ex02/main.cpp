/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:21:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 23:11:17 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void){

	{
		FragTrap fraggy("Steve");

		fraggy.attack("the great, blue sea");
		fraggy.takeDamage(2);
		fraggy.attack("the dark, green forest");
		fraggy.takeDamage(3);
		fraggy.beRepaired(20);
		fraggy.attack("the hot, sweltering dessert");
		fraggy.takeDamage(5);
		fraggy.attack("the icy, white glaciers");
		fraggy.takeDamage(10);
		fraggy.HighFiveGuys();
		fraggy.attack("the infinite, impenetrable void");
		fraggy.takeDamage(std::numeric_limits<unsigned int>::max());
		fraggy.beRepaired(20);
		fraggy.attack("hinmself");
		fraggy.takeDamage(20);
		fraggy.HighFiveGuys();
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
		ClapTrap clappy("Zeus");
		for (int i = 0; i < 4; i++)
		{
			clappy.attack("the great, blue sea");
			clappy.takeDamage(2);
			clappy.attack("the dark, green forest");
			clappy.takeDamage(2);
			clappy.beRepaired(10);
			clappy.attack("the hot, sweltering dessert");
			clappy.takeDamage(2);
			clappy.attack("the icy, white glaciers");
			clappy.takeDamage(2);
			clappy.attack("the infinite, impenetrable void");
		}
		clappy.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	return (0);
}