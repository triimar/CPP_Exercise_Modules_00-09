/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 19:57:09 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// const AAnimal* u = new AAnimal();
	// AAnimal Creature;
	
	std::cout << std::endl;
	std::cout << ">> " << j->getType() << " says: ";
	j->makeSound();
	std::cout << ">> " << i->getType() << " says: ";
	i->makeSound();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;
	// added purely virtual functions allow to use setidea(), getidea() with AAnimal pointer.
	AAnimal * a = new Dog();
	for (size_t i = 0; i < 100; i++) {
		a->setIdea(i, "SQUIRREL!");
	}
	std::cout << std::endl << ">> Dogs ideas:" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		std::cout << a->getIdea(i) << " ";
		if (i == 99)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	delete a;
	return 0;	
}