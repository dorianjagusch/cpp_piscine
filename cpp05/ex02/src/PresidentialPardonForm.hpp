/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:22:56 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/16 15:40:56 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <stdexcept>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm (std::string const _target) throw(std::runtime_error);
	PresidentialPardonForm( PresidentialPardonForm const &src );
	~PresidentialPardonForm();

	PresidentialPardonForm &	operator=( PresidentialPardonForm const &rhs );
	virtual void			execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException);

private:
	PresidentialPardonForm ();
	const std::string	_target;

};

#endif