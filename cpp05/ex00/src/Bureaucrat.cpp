/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:00:20 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 13:08:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Entered Grade is too high. The allowed range is [1,150]";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Entered Grade is too low. The allowed range is [1,150]";
}

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat( std::string name, int grade = 150 ) throw(GradeTooHighException, GradeTooLowException, std::runtime_error) : _name(name), _grade(grade)
{
	if (_name.empty())
		throw ( std::runtime_error("Name cannot be empty") );
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) throw(GradeTooHighException, GradeTooLowException) : _name(src._name), _grade(src._grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	if (_grade > 150)
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

std::ostream &	operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}