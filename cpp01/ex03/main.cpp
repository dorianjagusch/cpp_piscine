/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:23:55 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/21 19:13:38 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void )
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB mary("Mary");
		mary.attack();
		mary.setWeapon(club);
		club.setType("some other type of club");
		mary.attack();
	}
	{
		Weapon club = Weapon("");
		HumanA lisa("Lisa", club);
		lisa.attack();
		club.setType("some other type of club");
		lisa.attack();
	}
	{
		Weapon club = Weapon("");
		HumanB boaty_mcboatface("Boaty McBoatface");
		boaty_mcboatface.setWeapon(club);
		boaty_mcboatface.attack();
		club.setType("some other type of club");
		boaty_mcboatface.attack();
	}
	return 0;
}