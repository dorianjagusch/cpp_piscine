/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:20:21 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/20 22:33:41 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstring>


class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_num;
		std::string	_secret;
		int			_index;
		
	public:
		Contact( void );
		~Contact( void );
		void		setContact(std::string attributes[5], int index);
		std::string	getFirstName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickName( void ) const;
		std::string	getPhoneNumber( void ) const;
		std::string	getSecret( void ) const;
		int			getIndex( void ) const;
		void		printContact( void ) const;
};

#endif