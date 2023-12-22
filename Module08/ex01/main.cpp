/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:49:40 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/22 19:29:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <list>
#include <cstdlib>

int	main(void) {
	
	Span sp = Span(5);
	sp.addNumber(-6);
	sp.addNumber(-3);
	sp.addNumber(-17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Logest span: " << sp.longestSpan() << std::endl << std::endl;

	std::vector<int> myVec = getFilledIntContainer< std::vector<int> >(20000);
	std::cout << "Amount of numbers available " << myVec.size() << std::endl;
	Span sp2 = Span(20000);
	std::cout << "Max places available: "  << sp2.getMaxSize() << std::endl;
	try {
		sp2.addNumbers(myVec.begin(), myVec.end());
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Logest span: " << sp2.longestSpan() << std::endl;
	// std::cout << std::endl << sp2 << std::endl;
	std::cout << std::endl;
	
	std::list<int> myList = getFilledIntContainer< std::list<int> >(30);
	std::cout << "Amount of numbers available " << myList.size() << std::endl;
	Span sp3 = Span(10);
	std::cout << "Max places available: "  << sp3.getMaxSize() << std::endl;
	try {
		sp3.addNumbers(myList.begin(), myList.end());
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Logest span: " << sp3.longestSpan() << std::endl;
	// std::cout << std::endl << sp3 << std::endl;
	// system("leaks Span");
	return 0;
}