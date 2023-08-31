/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:27 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/31 15:21:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : _ContactsSet(0), _ContactIndex(0) {

	std::cout << "Welcome to your new PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook() {
	
	std::cout << "Your PhoneBook has been destroyed" << std::endl;
	return;
}

void		PhoneBook::_updateIndex() {
	
	_ContactIndex++;
	if (_ContactIndex == 8)
		_ContactIndex = 0;
}

int			PhoneBook::_getIndex() const {

	return this->_ContactIndex;
}

void		PhoneBook::_updateContactsSet() {
	
	if (_ContactsSet < 8)
		_ContactsSet++;
}
	
int			PhoneBook::_getContactsSet() const {
	
	return this->_ContactsSet;
}

bool	PhoneBook::_isValidInput(const std::string input) {
	
	for (const char *c = input.c_str(); *c != '\0'; ++c)
		{
			if (!std::isspace(static_cast<unsigned char>(*c)))
				return true;
		}
	return false;
	
}

std::string PhoneBook::_turnicate(std::string str) {

	if (str.length() < 11)
		return str;
	else {
		std::string turnicated = str.substr(0, 9);
		return turnicated + ".";
	}
}

std::string	PhoneBook::_askContactData(std::string Prompt) {
	
	std::string input;
	
	std::cout << Prompt;
	std::getline(std::cin, input);
	if (input.empty() || !_isValidInput(input))
		_askContactData(Prompt);
	return input;
}

void PhoneBook::addContact() {

	std::string input;
	int			slot;
	
	slot = _getIndex();
	std::cout << "INDEX IS: " << slot << std::endl;
	input = _askContactData("First name: ");
	this->_Contacts[slot].setFirstName(input);
	input = _askContactData("Last name: ");
	this->_Contacts[slot].setLastName(input);
	input = _askContactData("Nickname: ");
	this->_Contacts[slot].setNickname(input);
	input = _askContactData("Telephone number: ");
	this->_Contacts[slot].setPhoneNumber(input);
	input = _askContactData("Darkest secret: ");
	this->_Contacts[slot].setDarkestSecret(input);
	input.clear();
	_updateIndex();
	_updateContactsSet();
}

int PhoneBook::_askSearchIndex() {
	
	int inputIndex;
	
	std::cout << "Enter index of the entry to display: ";./
	if (inputIndex < 0 || inputIndex > 7)
	{
		std::cout << "Not a valid index" << std::endl;
		_askSearchIndex();
	}
	else if (inputIndex > _getContactsSet() - 1)
		std::cout << "Requested slot is still empty" << std::endl;
	
	return (inputIndex);
}

void PhoneBook::searchContacts() {

	int count = _getContactsSet();
	if (count == 0)
	{
		std::cout << "No contacts in the PhoneBook yet. ADD a contact" << std::endl;
				return;	
	}
	for (int i = 0; i < count; i++) {
		std::cout	<< std::setw(10) << std::right << i << "|"
					<< std::setw(10) << std::right << _turnicate(_Contacts[i].getFirstName()) << "|"
					<< std::setw(10) << std::right << _turnicate(_Contacts[i].getLastName()) << "|"
					<< std::setw(10) << std::right << _turnicate(_Contacts[i].getNickname()) << std::endl;
	}
	int index = _askSearchIndex();
	_displayContact(index);
}


void PhoneBook::_displayContact(int index) const {
	
	std::cout << _Contacts[index].getFirstName() << std::endl;
	std::cout << _Contacts[index]. getLastName() << std::endl;
	std::cout << _Contacts[index]. getNickname() << std::endl;
	std::cout << _Contacts[index]. getPhoneNumber() << std::endl;
	std::cout << _Contacts[index]. getDarkestSecret() << std::endl;
	
}
