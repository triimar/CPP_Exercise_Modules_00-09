/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:33:20 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/09 15:02:29 by tmarts           ###   ########.fr       */
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


ScavTrap::ScavTrap(const ScavTrap & rhs) : ClapTrap(rhs._name) {
	
	std::cout << "Scavtrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {

	if (this != &rhs)
		ClapTrap::operator=(rhs);
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