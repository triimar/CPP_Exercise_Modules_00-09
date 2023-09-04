/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:50:30 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 17:57:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
	
}
Weapon::~Weapon() {
	
}

void Weapon::setType(std::string newType) {

	this->_type = newType;
}

std::string	const & Weapon::getType() {
	
	return _type;
}