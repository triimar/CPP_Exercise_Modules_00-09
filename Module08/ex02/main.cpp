/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:55:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/23 00:08:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()	{
	MutantStack<int> mstack;
	std::cout << "MutantStack is empty? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Pushed 5 and 17" << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popped the top" << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Pushed 3, 5, 737 and 0" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iterating and printing the MutantStack: ";
	while (it != ite) {
	std::cout << *it << " ";
	++it;
	}
	std::cout << std::endl << std::endl;
	
	std::stack<int> s(mstack);
	std::cout << "Made a stack type copy of MutantStack: it cannot be iterated through." << std::endl << std::endl;
	// for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
	// 	std::cout << *it << " ";
	
	MutantStack<std::string> smutant;
	smutant.push("Hello!");
	smutant.push("This");
	smutant.push("is");
	smutant.push("MutantStack<std::string>!");
	smutant.push("Fancy!");
	std::cout << "Made a MutantStack of strings. using reverse_iterator to print it:" << std::endl;
	for (MutantStack<std::string>::const_reverse_iterator it = smutant.crbegin(); it != smutant.crend(); ++it)
		std::cout << *it << " "; 
	std::cout << std::endl;
	// system("leaks MutantStack");
	return 0;
}