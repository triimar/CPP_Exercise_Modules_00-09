/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:51:31 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 20:46:10 by tmarts           ###   ########.fr       */
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


FragTrap::FragTrap(const FragTrap & rhs) {
	
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = rhs;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {

	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_hitPoints = rhs._energyPoints;
	this->_energyPoints = rhs._attackDamage;
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {

	
std::cout << "FragTrap " << _name << " destruction!" << std::endl;
}

void FragTrap::highFiveGuys() {

	std::cout << "FragTrap " << _name << " yells: \"Can I get a high five!\""  << std::endl;
}