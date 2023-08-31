/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:27 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/31 19:49:57 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	
	for (const char *c = input.c_str(); *c != '\0'; ++c) {
		if (!std::isspace(static_cast<unsigned char>(*c)))
			return true;
	}
	return false;
	
}

std::string PhoneBook::_truncater(std::string str) {

	if (str.length() < 11)
		return str;
	else {
		std::string truncated = str.substr(0, 9);
		return truncated + ".";
	}
}

std::string	PhoneBook::_askInput(std::string Prompt) {
	
	std::string input;

	while (true) {
		std::cout << Prompt;
		std::getline(std::cin, input);
		if (!input.empty() && _isValidInput(input))
			break;
		std::cout << "Fieled cannot be left empty!" << std::endl;
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}

void PhoneBook::addContact() {
	
	int	slot = _getIndex();

	this->_Contacts[slot].setFirstName(_askInput("First name: "));
	this->_Contacts[slot].setLastName(_askInput("Last name: "));;
	this->_Contacts[slot].setNickname( _askInput("Nickname: "));
	this->_Contacts[slot].setPhoneNumber(_askInput("Telephone number: "));
	this->_Contacts[slot].setDarkestSecret(_askInput("Darkest secret: "));

	_updateIndex();
	_updateContactsSet();
	
	std::cout << "Contact successfully added!" << std::endl;
}

int PhoneBook::_askSearchIndex() {
	
	int	index = -1;
	std::string input;
	std::cout << "Enter index of the contact you wish to see: ";
	std::getline(std::cin, input);
	for (const char *c = input.c_str(); *c != '\0'; ++c) {
		if (!std::isdigit(static_cast<unsigned char>(*c))) {
			std::cout << "Index has to be numeric" << std::endl;
			return -1;
		}		
	}
	std::stringstream ss(input);
	if (ss >> index) {
		if (index < 0 || index > 7)
			std::cout << "Not a valid index" << std::endl;
		else if (index > _getContactsSet() - 1)
			std::cout << "Requested slot is still empty" << std::endl;
	}
	return index;
}

void PhoneBook::searchContacts() {

	int count = _getContactsSet();
	if (count == 0) {
		std::cout << "No contacts in the PhoneBook yet. ADD a contact" << std::endl;
		return;	
	}
	
	std::cout	<< std::setw(10) << std::right << "Index" << "|" 
				<< std::setw(10) << std::right << "FirstName" << "|" 
				<< std::setw(10) << std::right << "LastName" << "|"
				<< std::setw(10) << std::right << "NickName" << std::endl;
	
	for (int i = 0; i < 8; i++) {
		std::cout	<< std::setw(10) << std::right << i << "|"
					<< std::setw(10) << std::right << _truncater(_Contacts[i].getFirstName()) << "|"
					<< std::setw(10) << std::right << _truncater(_Contacts[i].getLastName()) << "|"
					<< std::setw(10) << std::right << _truncater(_Contacts[i].getNickname()) << std::endl;
	}
	
	int index = _askSearchIndex();
	if (index >=0 && index <= count - 1)
		_displayContact(index);
}


void PhoneBook::_displayContact(int index) const {
	
	std::cout << "First name: " << _Contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _Contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _Contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _Contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _Contacts[index]. getDarkestSecret() << std::endl;
}
