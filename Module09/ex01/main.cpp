/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:12:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/27 19:31:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: invalid input. Single string argument expected." << std::endl;
		return 1;
	}
	try {
		RPN current(static_cast<std::string>(argv[1]));
		current.solve();
	}
	catch(const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}