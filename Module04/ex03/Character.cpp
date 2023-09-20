/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:39:07 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 19:20:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("//Default//"), _invSlot(0), _trashNr(0) {
	std::cout << "\033[90mCONSTRUCTOR: default Character\033[0m" << std::endl;
		std::cout << "" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	for (size_t i = 0; i < 4; i++) {
		this->_unequippedI[i] = NULL;
	}
	return ;
}

Character::~Character() {
	std::cout << "\033[90mDESTRUCTOR: Character " << this->getName() << "\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete _inventory[i];
	}
	for (size_t i = 0; i < 4; i++) {
		if (this->_unequippedI[i])
			delete _unequippedI[i];
	}
	return ;
}

Character::Character(std::string name): _name(name), _invSlot(0), _trashNr(0) {
	std::cout << "\033[90mCONSTRUCTOR: Character " << this->getName() << "\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	for (size_t i = 0; i < 4; i++) {
		this->_unequippedI[i] = NULL;
	}
	return ;
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added
// to their inventory.

Character::Character(const Character& rhs):  _name(rhs._name), _invSlot(rhs._invSlot), _trashNr(rhs._trashNr) {
	std::cout << "\033[90mCOPY CONSTRUCTOR: Character " << this->getName() << "\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (size_t i = 0; i < 4; i++) {
		if (rhs._unequippedI[i])
			this->_unequippedI[i] = rhs._unequippedI[i]->clone();
		else
			this->_unequippedI[i] = NULL;
	}
}

Character& Character::operator=(const Character& rhs) {
	std::cout << "\033[90mCOPY ASSIGNMENT OPERATOR: Character " << this->getName() << "\033[0m" << std::endl;
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_invSlot = rhs._invSlot;
		this->_trashNr = rhs._trashNr;
		for (size_t i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		for (size_t i = 0; i < 4; i++) {
			if (this->_unequippedI[i])
				delete this->_unequippedI[i];
			if (rhs._unequippedI[i])
				this->_unequippedI[i] = rhs._unequippedI[i]->clone();
			else
				this->_unequippedI[i] = NULL;
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
	_invSlot = 0;
	while (_invSlot != 4 && _inventory[_invSlot] != NULL) {
		_invSlot++;
	}
	if (_invSlot == 4 && _inventory[3] != NULL) {
		std::cout << "ERROR all inventory slots are full, no new inventory can be equipped" << std::endl;
		return ;
	}
	_inventory[_invSlot] = m;
	std::cout << std::endl
		<< "New materia " << _inventory[_invSlot]->getType() << " equipped in slot " 
		<< _invSlot << std::endl;
	std::cout << "INVENTORY: ";
	for (size_t i = 0; i < 4; i++) {
		std::cout << "     " << i << "[";
		if (_inventory[i])
			std::cout << _inventory[i]->getType();
		std::cout << "]";
	}
	std::cout << std::endl << std::endl;
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "ERROR slot nr " << idx << " does not exist" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "ERROR slot nr " << idx << " is empty. Nothing to unequip" << std::endl;
		return ;	
	}
	if (_trashNr == 4)
	{
		std::cout << "ERROR unequipping not possible - too much trash has been created!" << std::endl; 
		return ;	
	}	
	std::cout << std::endl << "Slot nr " << idx << " containing " << _inventory[idx]->getType() <<  " will be unequipped" << std::endl;
	_unequippedI[_trashNr] = _inventory[idx];
	_inventory[idx] = NULL;
	_trashNr++;
	std::cout << "INVENTORY: ";
	for (size_t i = 0; i < 4; i++) {
		std::cout << "     " << i << "[";
		if (_inventory[i])
			std::cout << _inventory[i]->getType();
		std::cout << "]";
	}
	std::cout << std::endl << "TRASH:     ";
	for (size_t i = 0; i < 4; i++) {
		std::cout << "     " << i << "[";
		if (_unequippedI[i])
			std::cout << _unequippedI[i]->getType();
		std::cout << "]";
	}
	std::cout << std::endl << std::endl;

}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "ERROR slot nr " << idx << " does not exist" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "ERROR slot nr " << idx << " is empty. Nothing to use" << std::endl;
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