/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:06 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 10:56:43 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMeUtils.hpp"


int main(int argc, char *argv[]){
	if (argc == 1) {
		std::cout << "Error: input is expected." << std::endl;
		return 1;
	}
	if (!PmergeMeUtils::inputIsValid(++argv)) {
		std::cout << "Error: invalid input. Positive integer sequence expected." << std::endl;
		return 1;
	}
	std::vector<int> numVec, unsorted;
	std::deque<int> numDeque;
	PmergeMe::initiateUnsorted(unsorted, argv);
	
	//sorting vector
	clock_t startTime, endTime;
	double diffVec, diffDeque;
	startTime = clock();
	PmergeMe::initiateUnsorted(numVec, argv);
	PmergeMe::sortVec(numVec);
	endTime = clock();
	diffVec = static_cast<double>(endTime - startTime);
	
	//sorting deque
	startTime = clock();
	PmergeMe::initiateUnsorted(numDeque, argv);
	PmergeMe::sortDeque(numDeque);
	endTime = clock();
	diffDeque = static_cast<double>(endTime - startTime);
	
	//results:
	std::cout << "Before  : ";
	PmergeMe::printContainer(unsorted);
	std::cout << "After   : ";
	PmergeMe::printContainer(numVec);
	// PmergeMe::printContainer(numDeque);
	std::cout << "Time to process a range of " << numVec.size() \
		<< " elements with std::vector: " << diffVec << " µs" << std::endl;
	std::cout << "Time to process a range of " << numDeque.size() \
		<< " elements with std::deque:  " << diffDeque << " µs" << std::endl;
	return 0;
}

// std::is_sorted()is not cpp 98, for testing only;
// std::cout << "Data is sorted? " << std::boolalpha << std::is_sorted(numDeque.begin(), numDeque.end()) << std::endl;
// std::cout << "Data is sorted? " << std::boolalpha << std::is_sorted(numVec.begin(), numDeque.end()) << std::endl;

// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`