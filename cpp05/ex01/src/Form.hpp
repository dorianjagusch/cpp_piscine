/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:40:54 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:

	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return "Entered Grade is too high. The allowed range is [1,150]";
		}
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return "Entered Grade is too low. The allowed range is [1,150]";
		}
	};

	Form( std::string, int sign_grade, int exec_grade ) throw(GradeTooHighException, GradeTooLowException);
	Form( Form const &src ) throw(GradeTooHighException, GradeTooLowException);
	~Form();

	Form &		operator=( Form const &rhs );
	std::string	getName( void ) const ;
	bool		getSigned( void ) const ;
	int			getSignGrade( void ) const ;
	int			getExecGrade( void ) const ;
	bool		beSigned(Bureaucrat &bureaucrat) throw(GradeTooHighException, GradeTooLowException);

private:
	std::string const	_name;
	bool				_signed;
	int const			_sign_grade;
	int const			_exec_grade;

	Form();
};

std::ostream &operator<<( std::ostream &out, Form const &rhs );

#endif