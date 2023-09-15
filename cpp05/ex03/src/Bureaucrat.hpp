/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:58:27 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/15 10:29:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	Bureaucrat( std::string name, int grade ) throw(GradeTooHighException, GradeTooLowException);
	Bureaucrat( Bureaucrat const &src ) throw(GradeTooHighException, GradeTooLowException);
	~Bureaucrat();

	Bureaucrat &	operator=( Bureaucrat const &rhs );
	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void			incrementGrade( void ) throw(GradeTooHighException, GradeTooLowException);
	void			decrementGrade( void ) throw(GradeTooHighException, GradeTooLowException);
	void			signForm(AForm &form);
	void			executeForm(AForm const &form);
private:
	Bureaucrat();
	const std::string	_name;
	int					_grade;
};

std::ostream &	operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif