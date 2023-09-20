/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:48:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 18:35:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
	std::cout << "\033[90mCONSTRUCTOR: Default AMateria \033[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "\033[90mCONSTRUCTOR: AMateria \033[0m" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "\033[90mDESTRUCTOR: AMateria \033[0m" << std::endl;
}

AMateria::AMateria(const AMateria& rhs): _type(rhs._type){
	std::cout << "\033[90mCOPY CONSTRUCTOR: AMateria \033[0m" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	std::cout << "\033[90mCOPY ASIGNMENT OPERATOR: AMateria \033[0m" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}
	
std::string const& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Amateria is not material and has no effect whatsoever" << std::endl;
}