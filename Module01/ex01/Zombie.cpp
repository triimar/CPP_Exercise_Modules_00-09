/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:25 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 13:40:41 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	
	std::cout << ">> " << this->_name << " has lost it's head " << "<<" <<std::endl;
}

void Zombie::setName(std::string name) {
	
	this->_name = name;
}

void Zombie::announce() {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}