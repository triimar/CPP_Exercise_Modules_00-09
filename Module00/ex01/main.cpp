/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/31 15:32:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {

	PhoneBook	myPhoneBook;
	std::string	input;

	while (true)
	{
		std::cout << "Insert command (ADD / SEARCH / EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			myPhoneBook.addContact();
		else if (input == "SEARCH")
			myPhoneBook.searchContacts();
		else if (input == "EXIT")
			break;
	}
}
