/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:37 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/30 16:52:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

class	PhoneBook {
private:
	Contact _Contacts[8];
	int		_ContactsSet;
	int		_ContactIndex;
	
	std::string	_askContactData(std::string Prompt);
	void		_updateIndex();
	void		_updateContactsSet();
	int			_getIndex() const;
	int			_getContactsSet() const;
	int			_askSearchIndex();
	std::string _turnicate(std::string str);
	void		_displayContact(int index) const;
	bool		_isValidInput(const std::string input);
	

public:
	PhoneBook();
	~PhoneBook();

	void		addContact();
	void		searchContacts();
};