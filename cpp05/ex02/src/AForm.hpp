/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:40:54 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 14:04:28 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	class SignedFormException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return "Form is already signed";
		}
	};

	AForm();
	AForm( std::string, int sign_grade, int exec_grade ) throw(GradeTooHighException, GradeTooLowException);
	AForm( AForm const &src ) throw(GradeTooHighException, GradeTooLowException);
	virtual ~AForm();

	AForm &			operator=( AForm const &rhs );
	std::string		getName( void ) const ;
	bool			getSigned( void ) const ;
	int				getSignGrade( void ) const ;
	int				getExecGrade( void ) const ;
	void			beSigned(Bureaucrat &bureaucrat) throw(SignedFormException, GradeTooLowException);
	virtual void	execute( const Bureaucrat& executor ) const throw(SignedFormException, GradeTooLowException) = 0;

private:
	std::string const	_name;
	bool				_signed;
	int const			_sign_grade;
	int const			_exec_grade;

};

std::ostream &operator<<( std::ostream &out, AForm const &rhs );

#endif