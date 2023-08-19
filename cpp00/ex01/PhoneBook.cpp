/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:57:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/19 17:38:08 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void ){
	
}

void PhoneBook::add( void ){
	
	char	attributes[5][512];
	
	for (int i = 0; i < 5; i++)
	{
		std::cin >> attributes[i];
	}
	contacts[Contact::getNumInst() % 8](attributes)
}

void PhoneBook::search(int contact_ind) const {
	
}

void PhoneBook::exit( void ) {
	
}

