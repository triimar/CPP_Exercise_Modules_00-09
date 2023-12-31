/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:59 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 05:09:56 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// PmergeMe::PmergeMe() {}

// PmergeMe::~PmergeMe() {}



void PmergeMe::initiateUnsortedVec(std::vector<int>& empty, char **input)
{
	int num;

	for (int i = 0; input[i] != NULL; i++) {
		num = strtol(input[i], NULL, 10);
		empty.push_back(num);	
	}
}


void PmergeMe::FordJohnson(std::vector<std::vector<int>::iterator>& v, std::vector<int>::iterator& end, size_t chunk) {
	
	if (v.size() < 2)
		return ;
		
	std::vector<int>::iterator leftover = *v.end();
	if (v.size() % 2 != 0)
		leftover = *(v.end() - 1);
	std::cout << "Input array size: " << v.size() << " | LEFTOVER: ";
	if (leftover != *v.end())
		std::cout << *leftover << std::endl;
	
	std::vector<std::vector<int>::iterator> currentLevel;
	int i = 0;
	for (std::vector<std::vector<int>::iterator>::iterator it = v.begin(); it != v.end(); ++it) {
		if (i % 2 == 0 && it + 1 != v.end())
			currentLevel.push_back(*it);
		i++;
    }
	size_t size = currentLevel.size();
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size && *currentLevel[i] < *currentLevel[i + 1])
			PmergeMe::swapChunks(currentLevel[i], currentLevel[i + 1], end);
	}
	std::cout << "not yet in" << std::endl;
	FordJohnson(currentLevel, end, chunk * 2);
/*separate smaller and larger elements*/
	std::vector<int> tmpMain, pend;
	size_t halfChunk = chunk / 2;
	for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it)
		PmergeMe::insertChunk(tmpMain, tmpMain.end(), *it, halfChunk);
	//pend is always currentLevel elements (eg int iterator) + 1/2 chunk
	size_t	pendSize = 0;
	for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it) {
		PmergeMe::insertChunk(pend, pend.end(), (*it + halfChunk), halfChunk);
		pendSize++;
	}
	// appending leftovers to the pend chain
	std::cout << "before insert chunk" << std::endl;
	if (leftover != *v.end()) {
		std::cout << "in insert chunk" << *leftover << std::endl;
		PmergeMe::insertChunk(pend, pend.end(), leftover, halfChunk);
		pendSize++;
	}
	std::cout << "after insert chunk" << std::endl;
		
	std::cout << "SIZE: " << size << std::endl << "Full chunk:  " << chunk << std::endl;
	std::cout << "Main: ";
	PmergeMe::printContainer(tmpMain);
	std::cout << "Pend: ";
	PmergeMe::printContainer(pend);
	std::cout << std::endl;
	
	/*insertion part of the algorithm*/
	/*insert first element of the pend to the beginning of main*/
	tmpMain.insert(tmpMain.begin(), pend.begin(), (pend.begin() + halfChunk)); //tmpMain.insert(tmpMain.begin(), pend.begin(), (pend.begin() + 4));

	std::cout << "Main updated: ";
	PmergeMe::printContainer(tmpMain);
	std::cout << "Pend: ";
	PmergeMe::printContainer(pend);
	std::cout << "Pend element count: " << pendSize << std::endl;
	std::cout << "Starts: ";
	std::vector<int>::iterator start;
	for (size_t i = 0; i < pendSize; i++) {
		start = PmergeMeUtils::getIndexIt(pend.begin(), i, halfChunk);
		std::cout << "start: " << *start << " end: " << *(start + halfChunk - 1) << "on index " << i << " | "; 
	}
	std::cout << std::endl;
	
	std::vector<int>::iterator dst; //I get after binary search
	std::vector<int>::iterator elemLast; //elemFirst,
	size_t JacPrev = 1, JacNew = 3, JacNext = 3;//inserts = 1;
	size_t	inPos = JacNew;
	std::cout << "[size ]" << pendSize << " In positions: ";

	
	while (inPos <= pendSize || pendSize == 2)
	{
		// When pend chain is bigger than the the new jacobsthal number
		if (pendSize < JacNew)
		{
			inPos = JacPrev + 1;
			while (inPos <= pendSize)
			{
				std::cout << inPos << "! ";
				// elemFirst = PmergeMeUtils::getIndexIt(pend.begin(), inPos - 1, halfChunk);
				elemLast = PmergeMeUtils::getIndexIt(pend.begin(), inPos - 1, halfChunk) - 1;
				// size_t binres = PmergeMeUtils::binarySearch(tmpMain, 0, inPos, *elemLast, halfChunk);
				// std::cout<< "Looking for: " << *elemLast << "BinartSearch result " << binres << std::endl;
				// 			// dst = binary search where to isert;
				// tmpMain.insert(dst, elemFirst, elemLast);
				inPos++;
			}
			break ;
		}
		else
		{
			inPos = JacNew;
			while (JacPrev < inPos)
			{
				std::cout << inPos << "+ ";
				// elemFirst = PmergeMeUtils::getIndexIt(pend.begin(), inPos - 1, halfChunk);
				elemLast = PmergeMeUtils::getIndexIt(pend.begin(), inPos - 1, halfChunk) - 1;
				// size_t binres = PmergeMeUtils::binarySearch(tmpMain, 0, inPos, *elemLast, halfChunk);
				// std::cout << "Looking for: " << *elemLast << " BinartSearch result " << binres << std::endl;
				// elemFirst = PmergeMeUtils::getIndexIt(pend.begin(), inPos - 1, halfChunk);
				// elemLast = elemFirst + halfChunk - 1;
				// // dst = binary search where to isert;
				// tmpMain.insert(dst, elemFirst, elemLast);
				inPos--;
			}
			JacNext = PmergeMeUtils::getNextJacobstahl(JacPrev, JacNew);
			JacPrev = JacNew;
			JacNew = JacNext;
		}
	}
	std::cout << std::endl;
	


	
	
	// for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;
	// for (std::vector<std::vector<int>::iterator>::iterator it = currentLevel.begin(); it != currentLevel.end(); ++it)
	// 	if (it + 1 != currentLevel.end()
	// 		std::iter_swap(&it->first, &it->second);
	return ;
}


void PmergeMe::sortVec(std::vector<int>& v) {
	
	std::vector<std::vector<int>::iterator> itVector;
	std::vector<int>::iterator end = v.end();
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        itVector.push_back(it);
    }
	size_t size = itVector.size();
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size && *itVector[i] < *itVector[i + 1])
			PmergeMe::swapChunks(itVector[i], itVector[i + 1], end);
	}
	
	std::cout << "First swaps: ";
	for (std::vector<std::vector<int>::iterator>::iterator it = itVector.begin(); it != itVector.end(); ++it)
		std::cout << **it << " ";
	std::cout << std::endl;
	FordJohnson(itVector, end, 2);
	
	  // Insert smaller elements into main chain based on the Jacobsthal Numbers
  

}


//   typename C::iterator loc;
//   typename C::iterator curr;
//   size_t smlSize = (size + 1) / 2;
//   size_t jacPrev = 1, jac = 3, insCnt = 1;
// 
//   while (jacPrev < smlSize) {
//     size_t i = std::min(jac - 1, smlSize - 1);
//     if (size % 2 && i == smlSize - 1) {
//       loc = binarySearch(*(end - chunk), tmp.begin(),
//                          tmp.begin() + (insCnt++ + i--) * chunk, chunk);
//       insert_chunk(tmp, loc, end - chunk, chunk);
//     }
//     for (; i >= jacPrev; i--) {
//       curr = begin + (i * 2 + 1) * chunk;
//       loc = binarySearch(*curr, tmp.begin(),
//                          tmp.begin() + (insCnt++ + i) * chunk, chunk);
//     }
//     int temp = jac;
//     jac += 2 * jacPrev;
//     jacPrev = temp;
//   }