/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:51:31 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/09 15:03:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	
	_hitPoints = 100;
	_energyPoints = 100; 
	_attackDamage = 30;
	std::cout << "Default FragTrap has been constructed." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	_hitPoints= 100;
	_energyPoints = 100; 
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor did its thing." << std::endl;
}


FragTrap::FragTrap(const FragTrap & rhs) : ClapTrap(rhs._name) {
	
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {

	if (this != &rhs)
		ClapTrap::operator=(rhs);
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {

	
std::cout << "FragTrap " << _name << " destruction!" << std::endl;
}

void FragTrap::highFiveGuys() {

	std::cout << "FragTrap " << _name << " yells: \"Can I get a high five!\""  << std::endl;
}