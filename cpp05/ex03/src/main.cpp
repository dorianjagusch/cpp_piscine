/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	maggie("Margaret Evelyn Lenny", 140);
	Bureaucrat	bart("Bartholomew Jojo", 75);
	Bureaucrat	lisa("Lisa Marie", 50);
	Bureaucrat	marge("Marjorie Jaqueline", 5);
	Bureaucrat	homer("Homer Jay", 10);
	Intern		millhouse;

	AForm *array[] = {
		millhouse.makeForm("robotomy request", "Bender"),
		millhouse.makeForm("robotomy request", "C3PO"),
		millhouse.makeForm("robotomy request", "Wall-e"),
		millhouse.makeForm("robotomy request", "Optimus Prime"),
		millhouse.makeForm("shrubbery creation", "garden"),
		millhouse.makeForm("shrubbery creation", "park"),
		millhouse.makeForm("shrubbery creation", "school"),
		millhouse.makeForm("shrubbery creation", "The drawer"),
		millhouse.makeForm("presidential pardon", "Al Capone"),
		millhouse.makeForm("presidential pardon", "Ted Bundy"),
		millhouse.makeForm("presidential pardon", "Pablo Escobar"),
		millhouse.makeForm("presidential pardon", "Aileen Wuornos"),
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

	millhouse.makeForm("eating request", "Apple pie");

	return 0;
}