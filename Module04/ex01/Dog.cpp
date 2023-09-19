/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 20:17:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& rhs) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;	
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = rhs.type;
	*this->_brain = *rhs._brain;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "WOOF" << std::endl;
}

void	Dog::setIdea(int i, std::string idea) {
	if (i >= 0 && i < 100)
		this->_brain->ideas[i] = idea;
}

std::string Dog::getIdea(int i) const {
	if (i >= 0 && i < 100)
		return this->_brain->ideas[i];
	return "";
}