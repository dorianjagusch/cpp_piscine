/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:38:31 by djagusch          #+#    #+#             */
/*   Updated: 2023/08/23 19:13:32 by djagusch         ###   ########.fr       */
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
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* kitty = new WrongCat();

		if (kitty) {std::cout << kitty->getType() << " " << std::endl;}

		if (kitty) {kitty->makeSound();}
		if (kitty) {meta->makeSound();}

		if (kitty) {delete meta;}
		if (kitty) {delete kitty;}
	}

	return 0;
}