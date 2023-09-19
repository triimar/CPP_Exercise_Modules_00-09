/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:32 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:00:39 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unspecified creature") {
	std::cout << "AAnimal instance constructed" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs) {
	
	this->type = rhs.type;
	std::cout << "AAnimal assignment operator called" << std::endl;
	return *this;
}

std::string	AAnimal::getType() const {
	return this->type;
}
