/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:39:07 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/19 22:16:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("//Default//"), _recentlyAccessed(-1) {
		std::cout << "CONSTRUCTOR for a default character called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::~Character() {
	std::cout << "DESTRUCTOR for character " << this->getName() << " called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete _inventory[i];
	}
	return ;
}

Character::Character(std::string name): _name(name), _recentlyAccessed(-1) {
	std::cout << "CONSTRUCTOR for character " << this->getName() << " called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added
// to their inventory.

Character::Character(const Character& rhs):  _name(rhs._name), _recentlyAccessed(rhs._recentlyAccessed) {
	std::cout << "COPY CONSTRUCTOR for character " << this->getName() << " called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& rhs) {
	std::cout << "COPY ASSIGNMENT OPERATOR for character " << this->getName() << " called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_recentlyAccessed = rhs._recentlyAccessed;
		for (size_t i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "ERROR no Materia recieved to equip" << std::endl;
		return ;
	}
	_recentlyAccessed++;
	if (_recentlyAccessed == 4)
		_recentlyAccessed = 0;
	if (_inventory[_recentlyAccessed] != 0)
		std::cout 
			<< "No free inventory slots available! unequipping slot " 
			<< _recentlyAccessed << " " << _inventory[_recentlyAccessed]->getType() << std::endl;
	_inventory[_recentlyAccessed] = m;
	std::cout 
		<< "New materia " << _inventory[_recentlyAccessed]->getType() << " equipped in slot " 
		<< _recentlyAccessed << std::endl;
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "ERROR slot nr " << idx << "does not exist" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
		std::cout << "ERROR slot nr " << idx << "is empty. Nothing to unequip" << std::endl;
		return ;
	_inventory[idx] = NULL;
	std::cout << "Slot nr " << idx << " containing " << _inventory[idx]->getType() <<  " has been unequipped" << std::endl;
	_recentlyAccessed = idx--;
	
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "ERROR slot nr " << idx << "does not exist" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "ERROR slot nr " << idx << "is empty. Nothing to use" << std::endl;
		return ;	
	}
	_inventory[idx]->use(target);
}

// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
// The inventory is empty at construction. They equip the Materias in the first empty slot
// they find. This means, in this order: from slot 0 to slot 3. In case they try to add
// a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
// (but still, bugs are forbidden). The unequip() member function must NOT delete the
// Materia!