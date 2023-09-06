/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:20:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/06 21:20:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void modify(std::string &content, char *str1, char *str2)
{
	std::string search = str1;
	std::string substitute = str2;
	size_t position = 0;

	if (search.empty())
		return ;
	while ((position = content.find(search, position)) != std::string::npos) {
		content.erase(position, search.length());
		content.insert(position, substitute);
		position += substitute.length();
	}
	return ;
}

int main(int argc, char *argv[]) {

	if (argc != 4)
		return (std::cerr << "Incorrect number of arguments" << std::endl, 1);
	std::string	content;
	std::string name = argv[1];
	std::ifstream infile(name);
	if (!infile) 
		return (std::cerr << argv[1] << ": " << strerror(errno) << std::endl, 1);
	std::ofstream outfile(name + ".replace");
	if (!outfile) {
		infile.close();
		return (std::cerr << argv[1] << ": " << strerror(errno) << std::endl, 1);
	}
	getline(infile, content, '\x1A');
	if (!content.empty()) {
		modify(content, argv[2], argv[3]);
		outfile << content;
	}
	infile.close();
	outfile.close();	
	return (0);
}

/*

TESTS

touch testfile
./filestreams testfile "nothing" "nope"
rm testfile.replace
echo "hello\nthis is file\nit is working\n" >>testfile
./filestreams testfile hello "bye bye"
./filestreams Makefile " " "______"

*/