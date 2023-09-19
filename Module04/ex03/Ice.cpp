/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:57:32 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/19 21:52:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::~Ice() {
}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {

}

Ice&	Ice::operator=(const Ice& rhs) {
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