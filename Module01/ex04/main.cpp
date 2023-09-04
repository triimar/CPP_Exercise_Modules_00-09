/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:20:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 18:46:57 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

	if (argc == 4)
	{
		std::ifstream infile(argv[1]);
		if (!infile.is_open())
			std::cout << "No such file" << std::endl;
		std::ofstream outfile("tsaa");
		//1 file does not exist
		//strings are empty
		//string does not exist in file
		infile.close();
		outfile.close();
	}
	else
		std::cout << "Incorrect number of arguments";
	return (0);
}
// Create a program that takes three parameters in the following order: a filename and two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating. 
// All the member functions of the class std::string are allowed, except replace. Use them wisely!
// Of course, handle unexpected inputs and errors. You have to create and turn in your own tests to ensure your program works as expected.