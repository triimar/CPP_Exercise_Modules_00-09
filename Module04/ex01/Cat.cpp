/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 20:12:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& rhs) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = rhs;
}
	
Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = rhs.type;
	*this->_brain = *rhs._brain;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "MEOW" << std::endl;
}

void	Cat::setIdea(int i, std::string idea) {
	if (i >= 0 && i < 100)
		this->_brain->ideas[i] = idea;
}

std::string Cat::getIdea(int i) const {
	if (i >= 0 && i < 100)
		return this->_brain->ideas[i];
	return "";
}