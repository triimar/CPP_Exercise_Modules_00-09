/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:48:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/19 20:32:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
	
}

AMateria::AMateria(std::string const & type) : _type(type) {
	
}

AMateria::~AMateria() {
	
}

AMateria::AMateria(const AMateria& rhs): _type(rhs._type){
	
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}
	
std::string const& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	
}