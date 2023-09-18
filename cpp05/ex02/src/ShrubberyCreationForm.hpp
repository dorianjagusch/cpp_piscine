/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:10:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 13:08:51 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <stdexcept>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm (std::string const _target) throw(std::runtime_error);
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const &rhs );
	virtual void			execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException);

private:
	ShrubberyCreationForm ();
	const std::string	_target;
};

#endif