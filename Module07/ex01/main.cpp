/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:54:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/19 16:56:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstdlib>
#include <cctype>

void increment(int& i)
{
	i++;
}

void charToUpper(char& c) {
    c = std::toupper(static_cast<unsigned char>(c));
}

int main(void)
{
	int arr[] = {1, -4, 6};
	iter(arr, 3, print<int>);
	std::cout << std::endl;
	iter(arr, 3, increment);
	iter(arr, 3, print<int>);
	std::cout << std::endl;
	
	std::string str = "hello";
	iter(str.c_str(), str.length(), print<const char>);
	std::cout << std::endl;
	
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArray, 5, charToUpper);
	iter(charArray, 5, print<char>);
	std::cout << std::endl;
	std::string strs[] = {"you", "are", "here"};
	iter(strs, 3, print<std::string>);
	std::cout << std::endl;
	
	
}