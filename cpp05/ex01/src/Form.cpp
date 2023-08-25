/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:20:11 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 15:18:15 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name( "" ), _signed(false),  _sign_grade( 151 ), _exec_grade( 151 )
{}

Form::Form ( std::string name, int sign_grade, int exec_grade ) throw(GradeTooHighException, GradeTooLowException):
	_name( name ), _signed(false),  _sign_grade( sign_grade ), _exec_grade( exec_grade )
{
	if (_sign_grade < 1)
		throw (GradeTooHighException());
	else if (_sign_grade > 150)
		throw (GradeTooLowException());
	if (_exec_grade < 1)
		throw (GradeTooHighException());
	else if (_exec_grade > 150)
		throw (GradeTooLowException());
}

Form::Form( Form const & src ) throw(GradeTooHighException, GradeTooLowException) :
	_name( src._name ), _signed(false),  _sign_grade( src._sign_grade ), _exec_grade( src._exec_grade )
{
	if (_sign_grade < 1)
		throw (GradeTooHighException());
	else if (_sign_grade > 150)
		throw (GradeTooLowException());
	if (_exec_grade < 1)
		throw (GradeTooHighException());
	else if (_exec_grade > 150)
		throw (GradeTooLowException());
}

Form::~Form()
{}

Form &	Form::operator=( Form const & rhs )
{
	if( this != &rhs )
		_signed = rhs._signed;
	return (*this);
}

std::ostream & operator<<( std::ostream & out, Form const & rhs )
{
	out	<< "Form " << rhs.getName() << " signed:" << rhs.getSigned()
		<< " sign grade:" << rhs.getSignGrade() << "exec grade: " << rhs.getExecGrade()
		<< std::endl;
	return (out);
}

std::string	Form::getName( void ) const
{
	return(_name);
}

bool	Form::getSigned( void ) const
{
	return(_signed);
}

int	Form::getSignGrade( void ) const
{
	return(_sign_grade);
}

int	Form::getExecGrade( void ) const
{
	return(_exec_grade);
}

bool	Form::beSigned(Bureaucrat & bureaucrat) throw(GradeTooHighException, GradeTooLowException)
{
	if (_signed)
		return (true);
	if (bureaucrat.getGrade() >= 1 && bureaucrat.getGrade() < 151
		&& bureaucrat.getGrade() <= _sign_grade)
	{
		_signed = true;
		return (false);
	}
	throw (GradeTooLowException());
	return (false);
}
