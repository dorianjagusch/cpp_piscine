/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:00:20 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( std::string name, int grade )  throw(GradeTooHighException, GradeTooLowException) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) throw(GradeTooHighException, GradeTooLowException) : _name(src._name), _grade(src._grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs )
{
	if ( this != &rhs ){
		static_cast<std::string>(_name) = rhs.getName();
		_grade = rhs._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade( void ) throw(GradeTooHighException, GradeTooLowException)
{
	if (_grade - 1 < 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrementGrade( void ) throw(GradeTooHighException, GradeTooLowException)
{
	if (_grade + 1 > 150)
		throw (GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << _name << " could not sign " << form.getName()
		<< " because they are not authorised" << std::endl;
		return ;
	}
	catch (AForm::SignedFormException &e)
	{
		std::cout << _name << " could not sign " << form.getName()
		<< " because it has already been signed" << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
	return ;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << _name << " could not execute " << form.getName()
		<< " because they are not authorised" << std::endl;
		return ;
	}
	catch (AForm::SignedFormException &e)
	{
		std::cout << _name << " could not execute " << form.getName()
		<< " because it has not been signed" << std::endl;
		return ;
	}
	std::cout << _name << " executed Form " << form.getName() << std::endl;
	return ;
}

std::ostream &	operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}