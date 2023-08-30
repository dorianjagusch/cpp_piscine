/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:11:16 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if ( N <= 0 )
	{
		std::cout << "Provide a positive number of zombies, please. (> 0)" << std::endl;
		return 0 ;
	}
	if ( N > 1024 )
	{
		std::cout << "Provide a reasonable number of zombies, please (< 1024)" << std::endl;
		return 0 ;
	}
	Zombie* zombies = new Zombie[N];
	if ( zombies )
	{
		for ( int i = 0; i < N; i++ ){
			zombies[i].nameZombie(name);
		}
		return zombies ;
	}
	std::cerr << "Memory allocation failed..." << std::endl;
	return 0 ;
}