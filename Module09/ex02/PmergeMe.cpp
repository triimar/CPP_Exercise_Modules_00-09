/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:59 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 07:56:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMeUtils.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}


void PmergeMe::mergeVecPairs(std::vector<std::pair<int, int> >& paired) {
	size_t len = paired.size();
	if (len <= 1) return;
	size_t middle = len / 2;
	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;
	for (std::size_t i = 0; i < len; i++) {
    if (i < middle)
      left.push_back(paired[i]);
    else
      right.push_back(paired[i]);
	 }
	PmergeMe::mergeVecPairs(left);
	PmergeMe::mergeVecPairs(right);
	size_t leftLen = left.size(), rightLen = right.size();
  	size_t i = 0, j = 0;
	paired.clear();
  	while (i < leftLen && j < rightLen) 
	{
    	if (left.at(i).first < right.at(j).first)
     		paired.push_back(left.at(i++));
		else 
      	paired.push_back(right.at(j++));
  	}
  	while (i < leftLen) 
    	paired.push_back(left.at(i++));
	while (j < rightLen)
    	paired.push_back(right.at(j++));
}


void PmergeMe::sortVec(std::vector<int>& v) {
	size_t size = v.size();
	int struggler = -1;
	std::vector<std::pair<int, int> > paired;
	/*creating a pair vector with first element larger or equal*/
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size) {
			if (v[i] > v[i + 1])
				paired.push_back(std::make_pair(v[i], v[i + 1]));
			else 
				paired.push_back(std::make_pair(v[i + 1], v[i]));
		}
		else
			struggler = v[i];
	}
	v.clear();
	/*recursive merge sort of pairs according to the first element*/
	PmergeMe::mergeVecPairs(paired);
	/*separating pairs into two int arrays*/
	std::vector<int> pend;
	for (std::vector<std::pair<int, int> >::iterator it = paired.begin(); it != paired.end(); ++it) {
		v.push_back(it->first);
		pend.push_back(it->second);
	}
	/*adding the possible unpaired element to pend array and inserting the first pend element to main array*/
	if (struggler >= 0)
		pend.push_back(struggler);
	v.insert(v.begin(), pend[0]);
	/*starting insertion from pend to main*/
	size_t JacPrev = 1, JacNew = 3, JacNext = 3;
	size_t	posPend = JacNew, posMain;
	size_t pendLen = pend.size();
	size_t inserts = 1;
	while (posPend <= pendLen || pendLen == 2)
	{
		if (pendLen < JacNew) // When pend chain is bigger than the the new jacobsthal number
		{
			posPend = JacPrev + 1;
			while (posPend <= pendLen)
			{
				posMain = PmergeMe::binarySearch(v, 0, posPend + inserts, pend[posPend - 1]);
				v.insert((v.begin() + posMain), pend[posPend - 1]);
				inserts++;
				posPend++;
			}
			break ;
		}
		else
		{
			posPend = JacNew;
			while (JacPrev < posPend)
			{
				std::cout << posPend << "+ ";
				posMain = PmergeMe::binarySearch(v, 0, posPend + inserts, pend[posPend - 1]);
				v.insert((v.begin() + posMain), pend[posPend - 1]);
				inserts++;
				posPend--;
			}
			JacNext = PmergeMeUtils::getNextJacobstahl(JacPrev, JacNew);
			JacPrev = JacNew;
			JacNew = JacNext;
		}
	}
	/* printing */
	for (std::vector<std::pair<int, int> >::iterator it = paired.begin(); it != paired.end(); ++it) {
		std::cout << " | " << it->first << ";" << it->second; 
	}
	
	printContainer(v);
	printContainer(pend);
	
	std::cout << std::endl << "struggler: " << struggler << std::endl;

}

void PmergeMe::mergeDequePairs(std::deque<std::pair<int, int> >& paired) {
	size_t len = paired.size();
	if (len <= 1) return;
	size_t middle = len / 2;
	std::deque<std::pair<int, int> > left;
	std::deque<std::pair<int, int> > right;
	for (std::size_t i = 0; i < len; i++) {
    if (i < middle)
      left.push_back(paired[i]);
    else
      right.push_back(paired[i]);
	 }
	PmergeMe::mergeVecPairs(left);
	PmergeMe::mergeVecPairs(right);
	size_t leftLen = left.size(), rightLen = right.size();
  	size_t i = 0, j = 0;
	paired.clear();
  	while (i < leftLen && j < rightLen) 
	{
    	if (left.at(i).first < right.at(j).first)
     		paired.push_back(left.at(i++));
		else 
      	paired.push_back(right.at(j++));
  	}
  	while (i < leftLen) 
    	paired.push_back(left.at(i++));
	while (j < rightLen)
    	paired.push_back(right.at(j++));
}

void PmergeMe::sortDeque(std::Deque<int>& v) {
	size_t size = v.size();
	int struggler = -1;
	std::deque<std::pair<int, int> > paired;
	for (size_t i = 0; i < size; i += 2) {
		if (i + 1 < size) {
			if (v[i] > v[i + 1])
				paired.push_back(std::make_pair(v[i], v[i + 1]));
			else 
				paired.push_back(std::make_pair(v[i + 1], v[i]));
		}
		else
			struggler = v[i];
	}
	v.clear();
	PmergeMe::mergeVecPairs(paired);
	/*separating pairs into two int arrays*/
	std::deque<int> pend;
	for (std::deque<std::pair<int, int> >::iterator it = paired.begin(); it != paired.end(); ++it) {
		v.push_back(it->first);
		pend.push_back(it->second);
	}
	/*adding the possible unpaired element to pend array and inserting the first pend element to main array*/
	if (struggler >= 0)
		pend.push_back(struggler);
	v.insert(v.begin(), pend[0]);
	/*starting insertion from pend to main*/
	size_t JacPrev = 1, JacNew = 3, JacNext = 3;
	size_t	posPend = JacNew, posMain;
	size_t pendLen = pend.size();
	size_t inserts = 1;
	while (posPend <= pendLen || pendLen == 2)
	{
		if (pendLen < JacNew) // When pend chain is bigger than the the new jacobsthal number
		{
			posPend = JacPrev + 1;
			while (posPend <= pendLen)
			{
				posMain = PmergeMe::binarySearch(v, 0, posPend + inserts, pend[posPend - 1]);
				v.insert((v.begin() + posMain), pend[posPend - 1]);
				inserts++;
				posPend++;
			}
			break ;
		}
		else
		{
			posPend = JacNew;
			while (JacPrev < posPend)
			{
				std::cout << posPend << "+ ";
				posMain = PmergeMe::binarySearch(v, 0, posPend + inserts, pend[posPend - 1]);
				v.insert((v.begin() + posMain), pend[posPend - 1]);
				inserts++;
				posPend--;
			}
			JacNext = PmergeMeUtils::getNextJacobstahl(JacPrev, JacNew);
			JacPrev = JacNew;
			JacNew = JacNext;
		}
	}
	/* printing */
	for (std::deque<std::pair<int, int> >::iterator it = paired.begin(); it != paired.end(); ++it) {
		std::cout << " | " << it->first << ";" << it->second; 
	}
	
	printContainer(v);
	printContainer(pend);
	
	std::cout << std::endl << "struggler: " << struggler << std::endl;

}