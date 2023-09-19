/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:53:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:04:48 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = rhs;
}
	
WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	this->type = rhs.type;
	std::cout << "WrongCat assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "MEOW" << std::endl;
}