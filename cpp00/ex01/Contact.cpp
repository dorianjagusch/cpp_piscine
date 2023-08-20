/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:20:39 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/20 22:33:26 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ){
	_first_name = "";
	_last_name = "";
	_nick_name = "";
	_phone_num = "";
	_secret = "";
	_index = -1;
}

Contact::~Contact( void ){
	std::cout << "See you next time" << std::endl;
}

void Contact::setContact(std::string attributes[5], int index)
{
	_first_name = attributes[0];
	_last_name = attributes[1];
	_nick_name = attributes[2];
	_phone_num = attributes[3];
	_secret = attributes[4];
	_index = index;
}

std::string Contact::getFirstName( void ) const {
	return (_first_name);
}

std::string Contact::getLastName( void ) const {
	return (_last_name);
}

std::string Contact::getNickName( void ) const {
	return (_nick_name);
}

std::string Contact::getPhoneNumber( void ) const {
	return (_phone_num);
}

std::string Contact::getSecret( void ) const {
	return (_secret);
}

int Contact::getIndex( void ) const {
	return (_index);
}

void Contact::printContact( void ) const {
	std::cout << std::endl;
	std::cout << "First name:\t" << getFirstName() << std::endl;
	std::cout << "Last name:\t" << getLastName() << std::endl;
	std::cout << "Nick name:\t" << getNickName() << std::endl;
	std::cout << "Phone number:\t" << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:\t" << getSecret() << std::endl << std::endl;
}