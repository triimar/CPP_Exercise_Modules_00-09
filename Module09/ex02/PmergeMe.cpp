/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:59 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/29 22:17:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}



void PmergeMe::initiateUnsortedVec(std::vector<int>& empty, char **input)
{
	int num;

	for (int i = 0; input[i] != NULL; i++) {
		num = strtol(input[i], NULL, 10);
		empty.push_back(num);	
	}
}

void PmergeMe::FordJohnson(std::vector<std::vector<int>::iterator>& v, std::vector<int>::iterator& end, size_t chunk) {
	
	std::cout << "FJ" << std::endl;
	if (v.size() < 2)
		return ;
	std::vector<int>::iterator struggler;
	std::vector<std::vector<int>::iterator> currentLevel;
	int i = 0;
	for (std::vector<std::vector<int>::iterator>::iterator it = v.begin(); it != v.end(); ++it) {
		if (i % 2 == 0 && it + 1 != v.end())
			currentLevel.push_back(*it);
		i++;
    }
	//swapping 
	size_t size = currentLevel.size();
	if (size % 2 != 0)
		struggler = currentLevel[size - 1];
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size && *currentLevel[i] < *currentLevel[i + 1])
			PmergeMe::swapChunks(currentLevel[i], currentLevel[i + 1], end);
		// else if (i + 1 < size)
		// 	continue;
		// else if (i + 1 )
		// 	struggler = currentLevel[i];
	}
	FordJohnson(currentLevel, end, chunk * 2);
	std::cout << "chunk " << chunk << " size " << size << " " << *struggler << std::endl;
	
	// for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;
	// for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it)
	// 	if (it + 1 != currentLevel.end()
	// 		std::iter_swap(&it->first, &it->second);
	return ;
}

// void PmergeMe::sortVec(std::vector<int>& v) {
// 	//only for pair vctors
// 	size_t size = v.size();
// 	int struggler = -1;
// 	std::vector<std::pair<int, int> > paired;
// 	// if (size % 2 != 0)
// 	// 	struggler = v.back();
// 	for (size_t i = 0; i < size; i += 2) {
// 		if (i + 1 < size)
// 			paired.push_back(std::make_pair(v[i], v[i + 1]));
// 		else
// 			struggler = v[i];
// 	}
// 	v.clear();
// 	for (std::vector<std::pair<int, int> >::iterator it = paired.begin(); it != paired.end(); it++ ) {
// 		if (it->first < it->second)
// 			std::iter_swap(&it->first, &it->second);
// 		std::cout << "[" << it->first << ";" << it->second << "] ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << struggler << std::endl;
// }

void PmergeMe::sortVec(std::vector<int>& v) {
	
	std::vector<std::vector<int>::iterator> itVector;
	std::vector<int>::iterator end = v.end();
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        itVector.push_back(it);
    }
	size_t size = itVector.size();
	std::vector<int>::iterator struggler;
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size && *itVector[i] < *itVector[i + 1])
			PmergeMe::swapChunks(itVector[i], itVector[i + 1], end);
		else if (i + 1 < size)
			continue;
		else
			struggler = itVector[i];
	}
	
	std::cout << "First swaps: ";
	for (std::vector<std::vector<int>::iterator>::iterator it = itVector.begin(); it != itVector.end(); ++it)
		std::cout << **it << " ";
	std::cout << std::endl;
	FordJohnson(itVector, end, 2);
	
}