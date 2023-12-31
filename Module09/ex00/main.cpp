/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:08:46 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 10:16:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib> //for EXIT_FAILURE
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cerr << "Error: the program needs one file as input" << std::endl;
		return EXIT_FAILURE;
	}
	try	{
		BitcoinExchange bce("data.csv");
		std::string inputf = argv[1];
		bce.run(inputf);  
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}