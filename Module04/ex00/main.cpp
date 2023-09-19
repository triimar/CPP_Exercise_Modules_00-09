/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 17:20:30 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	std::cout << "---------------------------------------------------" << std::endl;
	
	const Animal* meta = new Animal();
	std::cout << ">> " << meta->getType() << " says: ";
	meta->makeSound();
	delete meta;
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
	std::cout << "---------------------------------------------------" << std::endl;
	
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	std::cout << std::endl;
	// b will not output the cat sound, but use the function 
	// from the parent that the pointer is declared as
	std::cout << ">> " << a->getType() << " says: ";
	a->makeSound();
	std::cout << ">> " << b->getType() << " says: ";
	b->makeSound();
	std::cout << std::endl ;
	delete a;
	delete b;
	
	std::cout << "---------------------------------------------------" << std::endl;
	// if we declare the WrongCat as the WrongCat pointer - it will make cat sound
	// and be deleted in the correct manner:
	const WrongCat *c = new WrongCat();
	std::cout << std::endl;
	std::cout << ">> " << c->getType() << " says: ";
	c->makeSound();
	std::cout << std::endl;
	delete c;
	return 0;	
}