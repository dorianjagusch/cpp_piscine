/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:57:40 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/18 12:11:45 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern( Intern const &src );
	~Intern();

	Intern &	operator=( Intern const &rhs );
	AForm *makeForm( std::string  const &name, std::string const &target ) const;
private:
	static AForm *makePresidentialForm( std::string const &target );
	static AForm *makeRobotomyForm( std::string const &target );
	static AForm *makeShrubberyForm( std::string const &target );
};

#endif