/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:20:11 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 14:53:35 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw(){
	return "Entered Grade is too high. The allowed range is [1,150]";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Entered Grade is too low. The allowed range is [1,150]";
}

const char* AForm::SignedFormException::what() const throw(){
			return "Form is already signed";
}

AForm::AForm() : _name( "" ), _signed(false),  _sign_grade( 151 ), _exec_grade( 151 )
{}

AForm::AForm ( std::string name, int sign_grade, int exec_grade ) throw(GradeTooHighException, GradeTooLowException, std::runtime_error):
	_name( name ), _signed(false),  _sign_grade( sign_grade ), _exec_grade( exec_grade )
{
	if( _name.empty() )
		throw(std::runtime_error("Name cannot be empty"));
	if (_sign_grade < 1)
		throw (GradeTooHighException());
	if (_sign_grade > 150)
		throw (GradeTooLowException());
	if (_exec_grade < 1)
		throw (GradeTooHighException());
	if (_exec_grade > 150)
		throw (GradeTooLowException());
}

AForm::AForm( AForm const &src ) throw(GradeTooHighException, GradeTooLowException) :
	_name( src._name ), _signed(false),  _sign_grade( src._sign_grade ), _exec_grade( src._exec_grade )
{
	if (_sign_grade < 1)
		throw (GradeTooHighException());
	if (_sign_grade > 150)
		throw (GradeTooLowException());
	if (_exec_grade < 1)
		throw (GradeTooHighException());
	if (_exec_grade > 150)
		throw (GradeTooLowException());
}

AForm::~AForm()
{
}

AForm &	AForm::operator=( AForm const &rhs )
{
	if( this != &rhs )
		_signed = rhs._signed;
	return *this;
}

std::ostream &operator<<( std::ostream &out, AForm const &rhs )
{
	out	<< "Form " << rhs.getName() << " signed: " << std::boolalpha << rhs.getSigned()
		<< " sign grade: " << rhs.getSignGrade() << " exec grade: " << rhs.getExecGrade()
		<< std::endl;
	return out;
}

std::string	AForm::getName( void ) const
{
	return(_name);
}

bool	AForm::getSigned( void ) const
{
	return(_signed);
}

int	AForm::getSignGrade( void ) const
{
	return(_sign_grade);
}

int	AForm::getExecGrade( void ) const
{
	return(_exec_grade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) throw(SignedFormException, GradeTooLowException)
{
	if (_signed)
	{
		throw (SignedFormException());
		return ;
	}
	if (bureaucrat.getGrade() >= 1 && bureaucrat.getGrade() < 151
		&& bureaucrat.getGrade() <= _sign_grade)
	{
		_signed = true;
		return ;
	}
	throw (GradeTooLowException());
	return ;
}
