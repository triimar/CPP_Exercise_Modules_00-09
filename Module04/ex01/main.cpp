/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 19:05:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	///////////////////////////////////////////////
	//GENERAL TEST + CONSTRUCTOR/DESTRUCTOR ORDER//
	std::cout << "---------------------------------------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << ">> " << j->getType() << " says: ";
	j->makeSound();
	std::cout << ">> " << i->getType() << " says: ";
	i->makeSound();
	std::cout << std::endl;
	delete j;
	delete i;
	///////////////////////////////////////
	//CREATING ARRAY OF CATS AND DOGS//////
	std::cout << "---------------------------------------------------" << std::endl;
	const Animal *pack[6];
	for (size_t i = 0; i < 4; i++){
		if (i < 2)
			pack[i] = new Cat;
		else
			pack[i] = new Dog;
		std::cout << pack[i]->getType() << ": ";
		pack[i]->makeSound();
	}
	for (size_t i = 0; i < 4; i++){
		delete pack[i];
	}
	//////////////////////////////////////
	//TESTING IF DEEP COPY IS CREATED/////
	std::cout << "---------------------------------------------------" << std::endl;
	Cat* a = new Cat();
	for (size_t i = 0; i < 100; i++) {
		a->setIdea(i, "FOOD");
	}
	std::cout << std::endl << ">> Cat A's ideas:" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		std::cout << a->getIdea(i) << " ";
		if (i == 99)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	Cat* b = new Cat;
	*b = *a;
	std::cout << std::endl << ">> CopyCat b's ideas:" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		std::cout << b->getIdea(i) << " ";
		if (i == 99)
			std::cout << std::endl;
	}
	for (size_t i = 0; i < 100; i++) {
		a->setIdea(i, "RUN");
	}
	std::cout << std::endl << ">> Cat A's new ideas:" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		std::cout << a->getIdea(i) << " ";
		if (i == 99)
			std::cout << std::endl;
	}
	std::cout << std::endl << ">> CopyCat b's ideas:" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		std::cout << b->getIdea(i) << " ";
		if (i == 99)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	delete a;
	delete b;
	std::cout << "---------------------------------------------------" << std::endl;
	// system("leaks brained_animals");
	
	return 0;	
}