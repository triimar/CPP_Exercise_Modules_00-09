/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 19:13:31 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& rhs): Animal(rhs), _brain(new Brain(*(rhs._brain))) {
	std::cout << "Cat copy constructor called" << std::endl;
}
	
Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if ( this != &rhs) {
		Animal::operator=(rhs);
		*(this->_brain) = *(rhs._brain); //currently there is no situation where _brain could be NULL,
	}									// (it cannot be set outside the class) otherwise it should be checked
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "MEOW" << std::endl;
}

void	Cat::setIdea(int i, std::string idea) {
		this->_brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const {
	return this->_brain->getIdea(i);

}