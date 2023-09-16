/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:58:23 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 15:33:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(){
	{
		try {
			
			std::cout << "===== Marge =====" << std::endl;
			Bureaucrat dude1("Margret", 1);
			std::cout << "Name: " << dude1.getName() << std::endl;
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			std::cout << dude1 << std::endl;
			dude1.decrementGrade();
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			dude1.incrementGrade();
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			Bureaucrat dude2 = dude1;
			std::cout << dude2.getName() << std::endl;
			std::cout << dude2.getGrade() << std::endl;
			std::cout << dude2 << std::endl  << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl  << std::endl;
		}
	}
	{
		try {
			std::cout << "===== Bob =====" << std::endl;
			Bureaucrat dude1("Bob", 100);
			std::cout << "Name: " << dude1.getName() << std::endl;
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			std::cout << dude1 << std::endl;

			Bureaucrat dude2(dude1);
			std::cout << dude2.getName() << std::endl;
			std::cout << dude2.getGrade() << std::endl;
			std::cout << dude2 << std::endl << std::endl; 
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {
			std::cout << "===== Dorian =====" << std::endl;
			Bureaucrat dude1("Dorian", 150);
			std::cout << "Name: " << dude1.getName() << std::endl;
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			std::cout << dude1 << std::endl;
			dude1.incrementGrade();
			dude1.incrementGrade();
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			dude1.decrementGrade();
			std::cout << "Grade: " << dude1.getGrade() << std::endl << std::endl;;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;;
		}
	}
	{
		try {
			std::cout << "===== Invalid Grades =====" << std::endl;
			Bureaucrat dude1("Dorian2", 0);
			std::cout << "Name: " << dude1.getName() << std::endl;
			std::cout << "Grade: " << dude1.getGrade() << std::endl;
			std::cout << dude1 << std::endl << std::endl;;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;;
		}

		try {
			Bureaucrat dude2("Dorian3", 151);
			std::cout << dude2.getName() << std::endl;
			std::cout << dude2.getGrade() << std::endl;
			std::cout << dude2 << std::endl << std::endl;;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;;
		}

		try {
			Bureaucrat dude2("", 150);
			std::cout << dude2.getName() << std::endl;
			std::cout << dude2.getGrade() << std::endl;
			std::cout << dude2 << std::endl << std::endl;;
		} catch ( std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}
}