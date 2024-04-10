/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:35:41 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/09 16:51:45 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
	//FragTrap params: h 100, e 100, a 30
	//Scavtrap params: h 100, e 50, a 20
	//
	// DiamondTrap params:
	// Hit points (FragTrap): 100
	// Energy points (ScavTrap): 50
	// Attack damage (FragTrap): 30

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap() {
	ScavTrap	tmp;
	_energyPoints = tmp.getEnergyPoints();
	std::cout << "Default DiamondTrap has been constructed with following parameters: hit points: " << _hitPoints
			<< " energy points: " << _energyPoints << " attack damage: " << _attackDamage << std::endl;
	
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	ScavTrap	tmp;
	_energyPoints = tmp.getEnergyPoints();
	std::cout << "DiamondTrap " << _name << " has been constructed with following parameters: hit points: " << _hitPoints
		<< " energy points: " << _energyPoints << " attack damage: " << _attackDamage << std::endl;
	
}

DiamondTrap::DiamondTrap(const DiamondTrap & rhs) : ScavTrap(rhs), FragTrap(rhs), _name(rhs._name){
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		_name = rhs._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "Hello, my ClapTrap name is " << ClapTrap::_name << " and my real name is "
		<< _name << "." << std::endl;
}