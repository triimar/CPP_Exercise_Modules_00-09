/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:43:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/23 00:05:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <ctime> //for std::time
#include <cstdlib> //for std::rand()


int main(void)
{
	std::srand(std::time(0));
	/* creating a list container, filling it with 200 "random" values*/
	std::cout << "LIST: " << std::endl;
	std::list<int> intList;
	for (int i = 0; i < 200; i++)
		intList.push_back(std::rand() % 1000 + 1);
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	/* easyfind() in list container*/
	try {
		std::list<int>::iterator it1 = easyfind(intList, 8);
		std::cout << *it1 << " found in the container in position " << std::distance(intList.begin(), it1) << "." << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << 8 << ": " << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator it2 = easyfind(intList, 653);
		std::cout << *it2 << " found in the container in position " << std::distance(intList.begin(), it2) << "." << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << 653 << ": " << e.what() << std::endl;
	}
	std::cout << std::endl;
	/* creating a vector container, filling it with 10 values*/
    std::cout << "VECTOR: " << std::endl;
    std::vector<int> intVec;
    for (int i = 0; i < 10; i++)
        intVec.push_back(i);
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    /* easyfind() in vector container */
    try {
        std::vector<int>::iterator it3 = easyfind(intVec, 8);
        std::cout << *it3 << " found in the container in position " << std::distance(intVec.begin(), it3) << "." << std::endl;
    } 
	catch (const std::exception& e) {
        std::cerr << 8 << ": " << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator it4 = easyfind(intVec, 3546);
        std::cout << *it4 << " found in the container in position " << std::distance(intVec.begin(), it4) << "." << std::endl;
    } 
	catch (const std::exception& e) {
        std::cerr << 3546 << ": " << e.what() << std::endl;
    }
	std::cout << std::endl;
	/* creating a deque container, filling it with 100 values*/
	std::cout << "DEQUE: " << std::endl;
	std::deque<int> intDeque;
	for (int i = 0; i < 100; i++)
		intDeque.push_back(std::rand() % 10 + 1);
	for (std::deque<int>::iterator it = intDeque.begin(); it != intDeque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	/* easyfind() in deque container*/
	try {
		std::deque<int>::iterator it5 = easyfind(intDeque, 8);
		std::cout << *it5 << " found in the container in position " << std::distance(intDeque.begin(), it5) << "." << std::endl;
    }
	catch(const std::exception& e) {
		std::cerr << 8 << ": " << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator it6 = easyfind(intDeque, -665);
		std::cout << *it6 << " found in the container in position " << std::distance(intDeque.begin(), it6) << "." << std::endl;
    } 
	catch(const std::exception& e) {
		std::cerr << -665 << ": " << e.what() << std::endl;
	}
}
