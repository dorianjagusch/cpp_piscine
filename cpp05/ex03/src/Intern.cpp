/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:06:48 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern( Intern const &src )
{
	*this = src;
}

Intern::~Intern()
{}

Intern &	Intern::operator=( Intern const &rhs )
{
	if( this != &rhs )
		(void)(rhs);
	return (*this);
}

AForm *Intern::makeShrubberyForm( std::string const &target )
{
	AForm *form;

	try {
		form = new ShrubberyCreationForm(target);
	} catch (std::exception &e){
		std::cerr << "Memory allocation error" << std::endl;
		return (NULL);
	}
	return (form);
}

AForm *Intern::makeRobotomyForm( std::string const &target )
{
	AForm *form;

	try {
		form = new RobotomyRequestForm(target);
	} catch (std::exception &e){
		std::cerr << "Memory allocation error" << std::endl;
		return (NULL);
	}
	return (form);
}

AForm *Intern::makePresidentialForm( std::string const &target )
{
	AForm *form;

	try {
		form = new PresidentialPardonForm(target);
	} catch (std::exception &e){
		std::cerr << "Memory allocation error" << std::endl;
		return (NULL);
	}
	return (form);
}


AForm *Intern::makeForm( std::string const &name, std::string const &target ) const
{
	static AForm*	(*funct[3])( std::string const &) = {
		makeShrubberyForm,
		makeRobotomyForm,
		makePresidentialForm
	};
	static const std::string	formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm						*form = 0;

	for (int i = 0; i < 3; i++){
		if ( formNames[i] == name ){
			form = funct[i](target);
			std::cout << "One of the interns created form " << name << std::endl;
			return (form);
		}
	}
	std::cout << "One of the interns failed to create " << name << std::endl;
	return (NULL);
}