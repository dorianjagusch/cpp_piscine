/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:38:31 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/25 09:44:23 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		std::cout << " Basic Tests:" << std::endl;
		//const AAnimal* meta = new AAnimal();
		const AAnimal* doggo = new Dog();
		const AAnimal* kitty = new Cat();

		if (kitty) {std::cout << kitty->getType() << " " << std::endl;}
		if (doggo) {std::cout << doggo->getType() << " " << std::endl;}

		if (doggo) {doggo->makeSound();}
		if (kitty) {kitty->makeSound();}
		//if (meta) {meta->makeSound();}

		//if (meta) {delete meta;}
		if (kitty) {delete kitty;}
		if (doggo) {delete doggo;}
	}
	std::cout << std::endl;
	std::cout << "Wrong animal stuff:" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* kitty = new WrongCat();

		if (kitty) {std::cout << kitty->getType() << " " << std::endl;}

		if (kitty) {kitty->makeSound();}
		if (meta) {meta->makeSound();}

		if (meta) {delete meta;}
		if (kitty) {delete kitty;}
	}
	std::cout << std::endl;
	std::cout << "Assignment test:" << std::endl;
	{
		Dog doggo1;
		std::cout << "before assignment" << std::endl;
		Dog doggo2 = doggo1;
		Dog doggo3 = Dog(doggo1);

		Cat kitty1;
		Cat kitty2 = kitty1;
		Cat kitty3 = Cat(kitty1);
	}
	std::cout << std::endl;
	std::cout << "Array test:" << std::endl;
	{
		AAnimal *doggo = new Dog();
		AAnimal *kitty = new Cat();

		const AAnimal* animals[6] = { new Dog(), new Dog(), new Cat(), new Cat(), doggo, kitty };
		std::cout  << "< All animals created >" << std::endl;
		for ( int i = 0; i < 6; i++ ) {
			delete animals[i];
		}
	}
	return 0;
}