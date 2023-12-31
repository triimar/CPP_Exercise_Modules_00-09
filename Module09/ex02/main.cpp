/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:06 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 07:50:28 by tmarts           ###   ########.fr       */
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
	std::vector<int> numVec;
	std::deque<int> numDeque;
	PmergeMe::initiateUnsorted(numVec, argv);
	PmergeMe::initiateUnsorted(numDeque, argv);
	
	PmergeMe::printContainer(numVec);
	PmergeMe::printContainer(numDeque);
	PmergeMe::sortVec(numVec);
	std::cout << "FINAL RESULT IN MAIN: ";
	PmergeMe::printContainer(numVec);
	std::cout << "Data is sorted? " << std::boolalpha << std::is_sorted(numVec.begin(), numVec.end()) << std::endl;
	return 0;
}