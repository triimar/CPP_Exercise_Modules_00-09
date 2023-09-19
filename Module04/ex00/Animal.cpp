/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:32 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:00:39 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unspecified creature") {
	std::cout << "Animal instance constructed" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& rhs) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal &rhs) {
	
	this->type = rhs.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "// indistinct animal noises //" << std::endl;
}
