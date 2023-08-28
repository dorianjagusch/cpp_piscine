/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:30:21 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/28 18:31:59 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main( void )
{
	try {
		Data* test = new Data("Jensen", 1, 45, "actor");
		Data* test2 = Serializer::deserialize( Serializer::serialize( test ) );
		std::cout	<< "Data:\t\t" << test << std::endl
					<< "deserialised:\t" << test2 << std::endl;
		delete test;
		return (0);
	}
	catch ( std::exception &e ){
		std::cout << e.what() << std::endl;
		return (1);
	}
}