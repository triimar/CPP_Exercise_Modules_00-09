/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:06:05 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/05 16:28:02 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {

	PhoneBook	myPhoneBook;
	std::string	input;

	while (true) // should check if stream is good std::cin.good() otherwise EOF can cause a problem
	{
		std::cout << "Insert command (ADD / SEARCH / EXIT)" << std::endl;
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			myPhoneBook.addContact();
		else if (input == "SEARCH")
			myPhoneBook.searchContacts();
		else if (input == "EXIT")
			break;
	}
	return 0;
}
