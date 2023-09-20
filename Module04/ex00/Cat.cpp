/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 18:51:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs) {
	std::cout << "Cat copy constructor called" << std::endl;
}
	
Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat assignment operator called" << std::endl;
	if ( this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "MEOW" << std::endl;
}