/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:33:20 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 20:50:30 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	
	_hitPoints = 100;
	_energyPoints = 50; 
	_attackDamage = 20;
	std::cout << "Default Scavtrap has been constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	_hitPoints= 100;
	_energyPoints = 50; 
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " exists now." << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap & rhs) {
	
	std::cout << "Scavtrap copy constructor called." << std::endl;
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {

	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_hitPoints = rhs._energyPoints;
	this->_energyPoints = rhs._attackDamage;
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is no more!" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {

	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name 
			<< " is deceased and cannot attack " << target << "." << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name 
			<< " is out of energy. Cannot move and cannot attack." << target << std::endl;
		return ;
	}	
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " is in attack mode. " << target
		<< " recieves " << _attackDamage << " points of damage!" << std::endl;
	return ;
	
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}