/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:58:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 21:04:58 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
	Array<int> intArr(3);
	std::cout << "intArr size is: " << intArr.size() << std::endl;
	try
	{
		intArr[0] = 5;
		intArr[1] = 7;
		intArr[2] = -1;
		intArr.printArray();
		intArr[-5];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Array<std::string> strArr = Array<std::string>(5);
	try
	{
		strArr[0] = "This";
		strArr[1] = "is";
		strArr[2] = "something.";
		strArr.printArray();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Array<std::string> otherArr = Array<std::string>(strArr);
	std::cout << "otherArr size is: " << otherArr.size() << std::endl;
	otherArr.printArray();
	Array<int> moreArr(30);
	std::cout << "moreArr size is: " << moreArr.size() << std::endl;
	moreArr.printArray();
	moreArr = intArr;
	std::cout << "moreArr new size is: " << intArr.size() << std::endl;
	moreArr.printArray();
	
}