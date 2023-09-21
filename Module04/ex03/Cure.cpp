/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:57:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 20:00:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure() : AMateria("cure") {
	std::cout << "\033[90mCONSTRUCTOR: Cure \033[0m" << std::endl;
}

Cure::~Cure() {
	std::cout << "\033[90mDESTRUCTOR: Cure \033[0m" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {
	std::cout << "\033[90mCOPY CONSTRUCTOR: Cure \033[0m" << std::endl;
}

Cure&	Cure::operator=(const Cure& rhs) {
	std::cout << "\033[90mCOPY ASSIGNMENT OPERATOR: Cure \033[0m" << std::endl;
	if ( this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}