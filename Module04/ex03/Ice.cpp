/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:57:32 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 18:03:40 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "\033[90mCONSTRUCTOR: Ice \033[0m" << std::endl;
}

Ice::~Ice() {
	std::cout << "\033[90mDESTRUCTOR: Ice \033[0m" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {
	std::cout << "\033[90mCOPY CONSTRUCTOR: Ice \033[0m" << std::endl;
}

Ice&	Ice::operator=(const Ice& rhs) {
	std::cout << "\033[90mCOPY ASSIGNMENT OPERATOR: Ice \033[0m" << std::endl;
	if ( this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AMateria* 	Ice::clone() const {
	return (new Ice());
}
	
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}