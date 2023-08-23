/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:38:31 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 20:18:25 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		std::cout << " Basic Tests:" << std::endl;
		const Animal* meta = new Animal();
		const Animal* doggo = new Dog();
		const Animal* kitty = new Cat();

		if (kitty) {std::cout << kitty->getType() << " " << std::endl;}
		if (doggo) {std::cout << doggo->getType() << " " << std::endl;}

		if (doggo) {doggo->makeSound();}
		if (kitty) {kitty->makeSound();}
		if (meta) {meta->makeSound();}

		if (meta) {delete meta;}
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
		if (kitty) {meta->makeSound();}

		if (kitty) {delete meta;}
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
		Animal *doggo = new Dog();
		Animal *kitty = new Cat();

		const Animal* animals[6] = { new Dog(), new Dog(), new Cat(), new Cat(), doggo, kitty };
		std::cout  << "< All animals created >" << std::endl;
		for ( int i = 0; i < 6; i++ ) {
			delete animals[i];
		}
	}
	return 0;
}