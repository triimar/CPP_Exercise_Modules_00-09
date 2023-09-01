/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:37 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/01 16:18:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

class	PhoneBook {
private:
	Contact _Contacts[8];
	int		_ContactsSet;
	int		_ContactIndex;
	
	std::string	_askInput(std::string Prompt);
	void		_updateIndex();
	void		_updateContactsSet();
	int			_getIndex() const;
	int			_getContactsSet() const;
	int			_askSearchIndex();
	std::string _truncater(std::string str);
	void		_displayContact(int index) const;
	bool		_isValidInput(const std::string input);
	

public:
	PhoneBook();
	~PhoneBook();

	void		addContact();
	void		searchContacts();
};

#endif