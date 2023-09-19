/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:57:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/19 20:33:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure() : AMateria("cure") {
	
}

Cure::~Cure() {
}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {
	
}

Cure&	Cure::operator=(const Cure& rhs) {
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