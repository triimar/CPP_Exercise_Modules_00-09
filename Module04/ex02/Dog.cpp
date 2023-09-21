/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 19:44:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& rhs): AAnimal(rhs), _brain(new Brain(*(rhs._brain))) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if ( this != &rhs) {
		this->type = rhs.type;
		*this->_brain = *rhs._brain;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "WOOF" << std::endl;
}

void	Dog::setIdea(int i, std::string idea) {
	this->_brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
	return this->_brain->getIdea(i);
}