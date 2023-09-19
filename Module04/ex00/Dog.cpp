/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:11:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;	
}

Dog& Dog::operator=(const Dog& rhs) {
	this->type = rhs.type;
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "WOOF" << std::endl;
}