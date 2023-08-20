/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:57:06 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/20 22:52:04 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string getInput( void );

PhoneBook::PhoneBook( void ){
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;
	std::cout << "               _.===========================._      ";
	std::cout << "╭╮╭╮╭╮╱╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮" << std::endl;
	std::cout << "            .'`  .-  - __- - - -- --__--- -.  `'.   ";
	std::cout << "┃┃┃┃┃┃╱╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱╭╯╰╮" << std::endl;
	std::cout << "        __ / ,'`     _|--|_________|--|_     `'. \\  ";
	std::cout << "┃┃┃┃┃┣━━┫┃╭━━┳━━┳╮╭┳━━╮╰╮╭╋━━╮" << std::endl;
	std::cout << "      /'--| ;    _.'\\ |  '         '  | /'._    ; | ";
	std::cout << "┃╰╯╰╯┃┃━┫┃┃╭━┫╭╮┃╰╯┃┃━┫╱┃┃┃╭╮┃" << std::endl;
	std::cout << "     //   | |_.-' .-'.'      ___      '.'-. '-._| | ";
	std::cout << "╰╮╭╮╭┫┃━┫╰┫╰━┫╰╯┃┃┃┃┃━┫╱┃╰┫╰╯┃" << std::endl;
	std::cout << "    (\\)   \\\"` _.-` /     .-'` _ `'-.     \\ `-._ `\"/  ";
	std::cout << "╱╰╯╰╯╰━━┻━┻━━┻━━┻┻┻┻━━╯╱╰━┻━━╯" << std::endl;
	std::cout << "    (\\)    `-'    |    .' .-'\" \"'-. '.   |    `-`   ";
	std::cout << "╱╭╮╭╮╱╱╱╱╱╭━━━╮╱╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭━╮" << std::endl;
	std::cout << "   (\\)            |   / .'(3)(2)(1)'. \\   |       ";
	std::cout << "╭╯╰┫┃╱╱╱╱╱┃╭━━╯╱╭╯╰╮╱╱╱╱╱╱╱╱╱╱╱╱┃╭╯" << std::endl;
	std::cout << "   (\\)            |  / / (4) .-.     \\ \\  |         ";
	std::cout << "╰╮╭┫╰━┳━━╮┃╰━━┳╮┣╮╭╋╮╭┳━┳━━╮╭━━┳╯╰╮" << std::endl;
	std::cout << "   (\\)            |  | |(5) (   )'==,J |  |         ";
	std::cout << "╱┃┃┃╭╮┃┃━┫┃╭━━┫┃┃┃┃┃┃┃┃╭┫┃━┫┃╭╮┣╮╭╯" << std::endl;
	std::cout << "  (\\)             |  \\ \\ (6) '-' (0) / /  |         ";
	std::cout << "╱┃╰┫┃┃┃┃━┫┃┃╱╱┃╰╯┃╰┫╰╯┃┃┃┃━┫┃╰╯┃┃┃" << std::endl;
	std::cout << " (\\)              |   \\ '.(7)(8)(9).' /   |         ";
	std::cout << "╱╰━┻╯╰┻━━╯╰╯╱╱╰━━┻━┻━━┻╯╰━━╯╰━━╯╰╯" << std::endl;
	std::cout << " (\\)           ___|    '. '-.._..-' .'    |         ";
	std::cout << "╭━━━━╮╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮" << std::endl;
	std::cout << " (\\)          /.--|      '-._____.-'      |         ";
	std::cout << "┃╭╮╭╮┃╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╯╰╮" << std::endl;
	std::cout << "  (\\)        (\\)  |\\_  _  __   _   __  __/|         ";
	std::cout << "╰╯┃┃┣┻━┫┃╭━━┳━━┳━━┳╮╭┳╮╭┳╮╭┳━╮╭┳━━┳━┻╮╭╋┳━━┳━╮" << std::endl;
	std::cout << " (\\)        (\\)   |                       |         ";
	std::cout << "╱╱┃┃┃┃━┫┃┃┃━┫╭━┫╭╮┃╰╯┃╰╯┃┃┃┃╭╮╋┫╭━┫╭╮┃┃┣┫╭╮┃╭╮╮" << std::endl;
	std::cout << "(\\)_._._.__(\\)    |                       |         ";
	std::cout << "╱╱┃┃┃┃━┫╰┫┃━┫╰━┫╰╯┃┃┃┃┃┃┃╰╯┃┃┃┃┃╰━┫╭╮┃╰┫┃╰╯┃┃┃┃" << std::endl;
	std::cout << " (\\\\\\\\\\\\\\\\\\\\)      '.___________________.'          ";
	std::cout << "╱╱╰╯╰━━┻━┻━━┻━━┻━━┻┻┻┻┻┻┻━━┻╯╰┻┻━━┻╯╰┻━┻┻━━┻╯╰╯" << std::endl;
	std::cout << "  '-'-'-'--'                                        " << std::endl;
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl << std::endl;
}

PhoneBook::~PhoneBook( void )
{
}

bool	PhoneBook::check_phone_num(std::string phone_num){
	for (size_t i = 0; i < phone_num.length(); i++){
		if ((phone_num[0] != '+' && !isdigit(phone_num[i]))
			|| !isdigit(phone_num[i]) || !isspace(phone_num[i]))
			return (false);
	}
	return (true);
}

void PhoneBook::add( void ){
	static int	index = 0;
	std::string prompts[5] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nick name: ",
		"Enter phone number: ",
		"Enter deepest, darkest, filthiest secret: "
	};
	std::string	attributes[5];

	for (int i = 0; i < 5; i++)
	{
		if (!std::cin.eof())
		{
			do {
				std::cout << prompts[i] << std::flush;
				attributes[i] = getInput();
			} while (!std::cin.eof() && attributes[i].length() == 0
				|| (i == 3 && check_phone_num(attributes[i])));
		}
	}
	if (!std::cin.eof()){
		this->_contacts[index].setContact(attributes, (index % 8) + 1);
		index = (index + 1) % 8;
		if (NumContacts < 8)
			NumContacts++;
	}
}

void PhoneBook::_printBook( void ) const {
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;

	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "_____________________________________________" << std::endl;

	for (int i = 0; i < 8; i++){
		if (this->_contacts[i].getIndex() < 0){
			if (i == 0)
				std::cout << "NO DATA" << std::endl;
			break;
		}

		first_name = this->_contacts[i].getFirstName();
		first_name = first_name.length() <= 10 ? first_name : first_name.substr(0,9).append(1, '.');
		last_name = this->_contacts[i].getLastName();
		last_name = last_name.length() <= 10 ? last_name : last_name.substr(0,9).append(1, '.');
		nick_name = this->_contacts[i].getNickName();
		nick_name = nick_name.length() <= 10 ? nick_name : nick_name.substr(0,9).append(1, '.');

		std::cout << "|" << std::setw(10) << this->_contacts[i].getIndex();
		std::cout << "|" << std::setw(10) << first_name;
		std::cout << "|" << std::setw(10) << last_name;
		std::cout << "|" << std::setw(10) << nick_name;
		std::cout << "|" << std::endl;
	}

	std::cout << "=============================================" << std::endl;
}

void PhoneBook::search( void ) const {
	std::string user_string;
	int			user_index;

	_printBook();
	if (NumContacts > 0)
	{
		std::cout << "Which contact would you like to display?" << std::endl;
		while (!std::cin.eof()){
			std::cout << "Enter Index: " << std::flush;
			user_string = getInput();
			user_index = atoi(user_string.c_str());
			if (user_string.length() == 1 && user_index > 0 && user_index <= NumContacts)
				break ;
			else
				std::cout << "Invalid entry. " << std::flush;
		}
		if (!std::cin.eof())
			this->_contacts[user_index - 1].printContact();
	}
	else if (!std::cin.eof())
		std::cout << "No contact to display." << std::endl;
}

int PhoneBook::NumContacts = 0;