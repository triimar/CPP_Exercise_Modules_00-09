/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:25 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/02 16:18:57 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: _name(name) {

}

Zombie::~Zombie() {
	
	std::cout << ">> " << this->_name << " has lost it's head " << "<<" <<std::endl;
}

void Zombie::announce() {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}