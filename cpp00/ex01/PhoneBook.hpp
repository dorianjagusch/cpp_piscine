/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:49:43 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/20 22:33:52 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ios>

class PhoneBook
{
	private:
		Contact		_contacts[8];
		void		_printBook() const;
		bool		check_phone_num(std::string phone_num);
		static int	NumContacts;

	public:
		PhoneBook( void );
		~PhoneBook( void );
		void add( void );
		void search( void ) const;
};

#endif