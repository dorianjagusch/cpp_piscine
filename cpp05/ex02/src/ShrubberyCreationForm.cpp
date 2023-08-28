/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:18:32 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("shrubbery form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) :
	AForm("shrubbery form", 145, 137), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	if( this != &rhs )
	{
		if (rhs.getSigned()){
			Bureaucrat tmp("tmp", 1);
			tmp.signForm(*this);
		}
	}
	return (*this);
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException)
{
	std::string fileName = _target + "_shubbery";
	std::ofstream file(fileName.c_str());

	if (!this->getSigned())
		throw(AForm::SignedFormException());
	else if(executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());


	if (!file.is_open() || !file.good())
		return;
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}