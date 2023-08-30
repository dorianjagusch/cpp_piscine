/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:06:37 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/30 12:25:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << std::setw( 20 ) << "Addresses:\t" << std::setw( 20 ) << &string << " ";
	std::cout << std::setw( 20 ) << stringPTR << " " << std::setw( 20 ) << &stringREF << std::endl;
	std::cout << std::setw( 20 ) << "Contents:\t" << std::setw( 20 ) << string << " ";
	std::cout << std::setw( 20 ) << *stringPTR << " " << std::setw( 20 ) << stringREF << std::endl;

	return 0 ;
}