/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:19:14 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 18:14:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("robotomy request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) :
	AForm("robotomy request", 72, 45), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException)
{
	static int	i;

	if (!this->getSigned())
		throw(AForm::SignedFormException());
	else if(executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());

	srand(time(NULL) + i++);

	std::cout << "                      _________" << std::endl;
	std::cout << "                     /~~~~~~~~~\\" << std::endl;
	std::cout << "                    (===========) ______________" << std::endl;
	std::cout << "                    |  ||  ||   ||~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "                    |  ||  ||   ||          (@) |" << std::endl;
	std::cout << "                    |  ||  ||   ||         //   |" << std::endl;
	std::cout << "                    |  ||  ||   ||        //    |" << std::endl;
	std::cout << "                    |  ||  ||   ||(@)===(o)     |" << std::endl;
	std::cout << "                    |  ||  ||   ||        \\     |" << std::endl;
	std::cout << "                    |           ||         \\    |" << std::endl;
	std::cout << "                    |~~~~~~~~~~~||         (@)  |" << std::endl;
	std::cout << "                    |___________||              |" << std::endl;
	std::cout << "       *Brrrr*      (___________)|              |" << std::endl;
	std::cout << "                     (_________) |    @--(o)    |" << std::endl;
	std::cout << "                       |     |   (              (" << std::endl;
	std::cout << "                       |     |    \\      (o)     \\" << std::endl;
	std::cout << "                       |     |     \\     /        \\" << std::endl;
	std::cout << "                       |     |      \\   @          \\" << std::endl;
	std::cout << "                       |_____|       \\              \\" << std::endl;
	std::cout << "                       |_____|        \\              \\" << std::endl;
	std::cout << "                       \\_____/     *Brrrrrrr*         \\" << std::endl;
	std::cout << "                         |/|            \\              \\" << std::endl;
	std::cout << "                      )  |/|             \\              \\" << std::endl;
	std::cout << "       *Brrrrrr*     (  ,|/|  / '         \\              \\" << std::endl;
	std::cout << "                      \\  |/| ( '           \\              \\" << std::endl;
	std::cout << "                _____  ) |/|' )         _   \\              \\" << std::endl;
	std::cout << "          |    |     |___|/|___________| |   \\              \\" << std::endl;
	std::cout << "          |====|     |_________________| |    \\              \\" << std::endl;
	std::cout << "         =|   _|      |_______________|  |     \\              \\" << std::endl;
	std::cout << "             |                           |      \\              \\" << std::endl;
	std::cout << "        _____|___________________________|_______)______________)" << std::endl;
	std::cout << "       |                                                        |" << std::endl;
	std::cout << "       |                                                        |" << std::endl;
	std::cout << "       |________________________________________________________|" << std::endl << std::endl;
	// by David Riley from https://ascii.co.uk/art/drill; I added the Brrrrr

	if ( float( rand() ) / float ( RAND_MAX ) <= 0.5)
		std::cout	<< "Robomtomy on patient "
					<< _target
					<< " was successful. You may take your toaster home.";
	else
		std::cout	<< "Robomtomy on patient "
					<< _target
					<< " failed. Womp womp... We can dispose of your toaster for you.";
	std::cout << std::endl;

}