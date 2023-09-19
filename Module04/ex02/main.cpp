/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 21:24:56 by tmarts           ###   ########.fr       */
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
	
	return 0;	
}