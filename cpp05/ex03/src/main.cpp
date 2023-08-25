/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 17:23:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat maggie("Margaret Evelyn Lenny", 140);
	Bureaucrat bart("Bartholomew Jojo", 75);
	Bureaucrat lisa("Lisa Marie", 50);
	Bureaucrat marge("Marjorie Jaqueline", 5);
	Bureaucrat homer("Homer Jay", 10);

	AForm *array[] = {
		new RobotomyRequestForm("Bender"),
		new RobotomyRequestForm("C3PO"),
		new RobotomyRequestForm("Wall-e"),
		new RobotomyRequestForm("Optimus Prime"),
		new ShrubberyCreationForm("garden"),
		new ShrubberyCreationForm("park"),
		new ShrubberyCreationForm("school"),
		new ShrubberyCreationForm("The drawer"),
		new PresidentialPardonForm("Al Capone"),
		new PresidentialPardonForm("Ted Bundy"),
		new PresidentialPardonForm("Pablo Escobar"),
		new PresidentialPardonForm("Aileen Wuornos"),
	};

	std::cout << "============== Maggie ==============" << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		maggie.signForm(*(array[i]));
	}
	std::cout << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		maggie.executeForm(*(array[i]));
	}
	std::cout << std::endl;
		std::cout << "============== Bart ==============" << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		bart.signForm(*(array[i]));
	}
	std::cout << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		bart.executeForm(*(array[i]));
	}
	std::cout << std::endl;
		std::cout << "============== Lisa ==============" << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		lisa.signForm(*(array[i]));
	}
	std::cout << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		lisa.executeForm(*(array[i]));
	}
	std::cout << std::endl;
		std::cout << "============== Marge ==============" << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		marge.signForm(*(array[i]));
	}
	std::cout << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		marge.executeForm(*(array[i]));
	}
	std::cout << std::endl;
		std::cout << "============== Homer ==============" << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		homer.signForm(*(array[i]));
	}
	std::cout << std::endl;
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		homer.executeForm(*(array[i]));
	}
	for (size_t i = 0; i < sizeof(array) / sizeof(AForm *); i++){
		delete array[i];
	}
	return (0);
}