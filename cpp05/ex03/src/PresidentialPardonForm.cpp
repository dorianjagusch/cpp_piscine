/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:50:37 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 18:14:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	AForm("presidential pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) :
	AForm("presidential form", 25, 5), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
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

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException)
{
	std::ofstream file;

	if (!this->getSigned())
		throw(AForm::SignedFormException());
	else if(executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::cout	<< _target << " was pardoned by the 7-times Worst Dressed Sentient"
				<< "Being in the Known Universe winner(?) Zaphod Beeblebrox" << std::endl;
}