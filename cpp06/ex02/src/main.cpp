/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:45:44 by djagusch          #+#    #+#             */
/*   Updated: 2023/09/20 09:20:34 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

class D : public Base
{};

Base * generate( void )
{
	int random = std::rand() % 3;
	try {
		if (random == 0)
			return new A;
		else if (random == 1)
			return new B;
		else
			return new C;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return NULL;
	}
}

void identify( Base* p )
{
	if (p && dynamic_cast<A*>(p)){
		std::cout << "Pointer is of type A" << std::endl;
	} else if (p && dynamic_cast<B*>(p)){
		std::cout << "Pointer is of type B" << std::endl;
	} else if (p && dynamic_cast<C*>(p)){
		std::cout << "Pointer is of type C" << std::endl;
	} else {
		std::cout << "Pointer is of unknown type" << std::endl;
	}
}

void identify( Base& p )
{
	Base temp;
	
	try {
		temp = dynamic_cast<A&>(p);
		std::cout << "Reference is of type A" << std::endl;
		return;
	} catch (std::exception &e) {};
	try {
		temp = dynamic_cast<B&>(p);
		std::cout << "Reference is of type B" << std::endl;
		return;
	} catch (std::exception &e) {};
	try {
		temp = dynamic_cast<C&>(p);
		std::cout << "Reference is of type C" << std::endl;
		return;
	} catch (std::exception &e) {
		std::cout << "Reference is of unknown type" << std::endl;
	};
}

int main(void)
{
	Base*	array[20];
	std::srand( static_cast<unsigned int>( std::time( NULL ) ) );

	for (int i = 0; i < 18; i++){
		array[i] = generate();
	}
	array[18] = new D;;
	array[19] = NULL;
	for (int i = 0; i < 20; i++){
		identify( array[i] );
		if ( array[i] )
			identify( *array[i] );
	}
	for (int i = 0; i < 19; i++){
		if (array[i])
			delete array[i];
	}
	return 0;
}