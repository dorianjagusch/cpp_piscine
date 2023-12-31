/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:52 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
	std::string inputs[] = {
		"DEBUG",
		"INFO",
		"ERROR",
		"WARNING",
		"warning",
		"347623984",
		"kjkevbijk",
		""
	};
	Harl	harl;

	for (int i = 0; i < 8; i++){
		std::cout << "Input: " << inputs[i] << std::endl;
		harl.complain(inputs[i]);
	}
	std::cout << "Input: Cleared string"<< std::endl;
	inputs[0].clear();
		harl.complain(inputs[0]);
	return 0;
}