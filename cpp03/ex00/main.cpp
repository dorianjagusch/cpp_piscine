/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:21:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/22 21:50:51 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "ClapTrap.hpp"

int main(void){

	{
		ClapTrap clappy("Steve");

		clappy.attack("the great, blue sea");
		clappy.takeDamage(2);
		clappy.attack("the dark, green forest");
		clappy.takeDamage(3);
		clappy.beRepaired(20);
		clappy.attack("the hot, sweltering dessert");
		clappy.takeDamage(5);
		clappy.attack("the icy, white glaciers");
		clappy.takeDamage(10);
		clappy.attack("the infinite, impenetrable void");
		clappy.takeDamage(std::numeric_limits<unsigned int>::max());
		clappy.beRepaired(20);
		clappy.attack("hinmself");
		clappy.takeDamage(20);
	}
	{
		ClapTrap clappy("Bobby");

		clappy.attack("the great, blue sea");
		clappy.takeDamage(5);
		clappy.attack("the dark, green forest");
		clappy.takeDamage(3);
		clappy.attack("the hot, sweltering dessert");
		clappy.takeDamage(5);
		clappy.attack("the icy, white glaciers");
		clappy.takeDamage(10);
		clappy.attack("the infinite, impenetrable void");
		clappy.takeDamage(std::numeric_limits<unsigned int>::max());
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