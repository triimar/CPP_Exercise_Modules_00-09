/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:01 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/31 15:32:17 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {

} 

Contact::~Contact() {

}

void	Contact::setFirstName(std::string input) {

	this->_FirstName = input;
}

void	Contact::setLastName(std::string input) {

	this->_LastName = input;
}

void	Contact::setNickname(std::string input) {
	
	this->_Nickname = input;
}

void	Contact::setPhoneNumber(std::string input) {

	this->_PhoneNumber = input;

}

void	Contact::setDarkestSecret(std::string input) {

	this->_DarkestSecret = input;
}

std::string Contact::getFirstName() const {

	return this->_FirstName;
}

std::string Contact::getLastName() const {
	
	return this->_LastName;
}

std::string Contact::getNickname() const {
	
	return this->_Nickname;
}

std::string Contact::getPhoneNumber() const {

	return this->_PhoneNumber;	
}

std::string Contact::getDarkestSecret() const {
	
	return this->_DarkestSecret;
}
