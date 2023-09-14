/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:35:41 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 22:08:13 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : {
	
}

DiamondTrap::DiamondTrap(std::string name) {
	
}

DiamondTrap::DiamondTrap(const DiamondTrap & rhs) {
	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called." << std::endl;
}

// Hit points (FragTrap)
// Energy points (ScavTrap)
// Attack damage (FragTrap)

void DiamondTrap::whoAmI() {
	std::cout << "Hello, my ClapTrap name is " << ClapTrap::_name << " and my real name is "
		<< _name << "." << std::endl;
}