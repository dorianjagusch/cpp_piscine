/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 14:36:13 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat maggie("Margaret Evelyn Lenny", 100);
	Bureaucrat bart("Bartholomew Jojo", 70);
	Bureaucrat lisa("Lisa Marie", 40);
	Bureaucrat marge("Marjorie Jaqueline", 5);
	Bureaucrat homer("Homer Jay", 10);

	try{
		Form array[] = {
			Form("* Pacifier sucking sounds *", 150, 99),
			Form("Kiss my A$$", 75, 70),
			Form("* Saxophone sounds *", 50, 30),
			Form("Hrmmm....", 5, 7),
			Form("D'oh", 15, 7),
			//Form("FAIL", 0, 7),
			//Form("FAIL2", 12, 151)
		};
		
		std::cout << "============== Maggie ==============" << std::endl;
		for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			std::cout << array[i] << std::endl;
		}
		
		std::cout << "============== Maggie ==============" << std::endl;
			for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			maggie.signForm(array[i]);
		}
		std::cout << std::endl;
			std::cout << "============== Bart ==============" << std::endl;
		for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			bart.signForm(array[i]);
		}
		std::cout << std::endl;
			std::cout << "============== Lisa ==============" << std::endl;
		for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			lisa.signForm(array[i]);
		}
		std::cout << std::endl;
			std::cout << "============== Marge ==============" << std::endl;
		for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			marge.signForm(array[i]);
		}
		std::cout << std::endl;
			std::cout << "============== Homer ==============" << std::endl;
		for (size_t i = 0; i < sizeof(array) / sizeof(Form); i++){
			homer.signForm(array[i]);
		}
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}