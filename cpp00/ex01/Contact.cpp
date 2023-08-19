/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:20:39 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/19 17:35:18 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::~Contact (void)
{
	Contact::_numInst -= 1;
}

Contact::Contact(std::string attributes[5])
{
	_first_name = attributes[1] ;
	_last_name = attributes[2] ;
	_nick_name = attributes[3] ;
	_phone_num = attributes[4] ;
	_secret = attributes[5];
	Contact::_numInst += 1;
}

int Contact::getNumInst(void)
{
	return (Contact::_numInst);
}

int		Contact::_numInst = 0;