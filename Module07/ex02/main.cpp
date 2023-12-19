/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:58:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/19 17:32:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> intArr(3);
	std::cout << "intArr size is: " << intArr.size() << std::endl;
	try
	{
		intArr[0] = 5;
		intArr[1] = 7;
		intArr[2] = -1;
		intArr[-5];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << intArr << std::endl << std::endl;
	// array of std::string:
	Array<std::string> strArr(5);
	try
	{
		strArr[0] = "This";
		strArr[1] = "is";
		strArr[2] = "something.";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "strArr size is: " <<strArr.size() << std::endl;
	std::cout << strArr << std::endl << std::endl;
	// array of std::string instantiated with copy constructor
	Array<std::string> otherArr(strArr);
	
	std::cout << "otherArr size is: " << otherArr.size() << std::endl;
	std::cout << otherArr << std::endl << std::endl;
	// array of int instantiated and then changed with copy assignemnt operator
	Array<int> moreArr(30);
	try
	{
		for (unsigned int i = 0; i < moreArr.size(); i++)
			moreArr[i] = i;
	}	
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "moreArr size is: " << moreArr.size() << std::endl;
	std::cout << moreArr << std::endl;
	moreArr = intArr;
	std::cout << "moreArr new size is: " << moreArr.size() << std::endl;
	std::cout << moreArr << std::endl;
	int * a = new int();
	std::cout << *a << std::endl;
}