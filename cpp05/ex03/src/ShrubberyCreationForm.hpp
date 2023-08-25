/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:10:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 17:47:18 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm (std::string const _target);
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );
	virtual void			execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException);

private:
	ShrubberyCreationForm ();
	const std::string	_target;

};

#endif