/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:08:49 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/09 14:16:41 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "Default ClapTrap has been constructed." << std::endl;
}
	
ClapTrap::ClapTrap(std::string name): 
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)  {

	std::cout << "ClapTrap " << _name << " has been constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & rhs) : 
		_name(rhs._name), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage){
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_hitPoints = rhs._energyPoints;
		this->_energyPoints = rhs._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name 
			<< " has not enough hit points to attack " << target << "." << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name 
			<< " is out of energy. Cannot attack" << target << "." << std::endl;
		return ;
	}	
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< " causing " << _attackDamage << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name 
			<< " has not enough hit points take any more damage..." << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name 
			<< " is out of energy. Cannot take any damage..." << std::endl;
		return ;
	}
	if (amount >= _hitPoints) 
	{
		std::cout << amount << " points of damage is too much for ClapTrap " 
			<< _name << " to take ... damage irreversable!" << std::endl;
		_hitPoints = 0;
		return;
	}
	_hitPoints = _hitPoints - amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and has "
	<< _hitPoints << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name 
		<< "'s damage is beyond repair." << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name 
			<< " is out of energy. It cannot repair itself..." << std::endl;
		return ;
	}
	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself and gets " 
		<< amount << " hit points back!" << std::endl; 
}