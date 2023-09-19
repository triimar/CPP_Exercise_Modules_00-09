/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:11:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = rhs;
}
	
Cat& Cat::operator=(const Cat& rhs) {
	this->type = rhs.type;
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "MEOW" << std::endl;
}