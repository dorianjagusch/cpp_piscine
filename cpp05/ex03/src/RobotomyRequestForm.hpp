/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:10:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm (std::string const _target);
	RobotomyRequestForm( RobotomyRequestForm const &src );
	~RobotomyRequestForm();

	RobotomyRequestForm &	operator=( RobotomyRequestForm const &rhs );
	virtual void			execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException);

private:
	RobotomyRequestForm ();
	const std::string	_target;
};

#endif