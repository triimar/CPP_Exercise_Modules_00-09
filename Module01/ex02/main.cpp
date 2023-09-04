/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 18:12:06 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << std::endl << "[ADDRESSES]" << std::endl;
	std::cout << "string variable (&str): \t" << &str << std::endl;
	std::cout << "stringPTR (stringPTR): \t\t" << stringPTR << std::endl;
	std::cout << "stringREF (&stringREF): \t" << &stringREF << std::endl;
	// std::cout << "stringPTR (&stringPTR): \t" << &stringPTR << std::endl;
	
	std::cout << std::endl << "[VALUES]" << std::endl;
	std::cout << "string variable (str): \t\t" << str << std::endl;
	std::cout << "stringPTR (*stringPTR): \t" << *stringPTR << std::endl;
	std::cout << "stringREF (stringREF): \t\t" << stringREF << std::endl;
	std::cout << std::endl;
}