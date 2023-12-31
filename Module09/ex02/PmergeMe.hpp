/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:18:14 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 07:51:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
	
	template <typename T>
	static size_t 	binarySearch(T& container, size_t start, size_t end, int target);
	
	static void		mergeVecPairs(std::vector<std::pair<int, int> >& paired);
	static void		mergeDequePairs(std::deque<std::pair<int, int> >& paired)
	
;public:
	PmergeMe();
	~PmergeMe();
	
	template <typename T>
	static void initiateUnsorted(T& empty, char **input);
	
	static void sortVec(std::vector<int>& unsorted);
	static void sortDeque(std::deque<int>& unsorted);

	template <typename T>
	static void printContainer(const T& container);
	
};

// member function templates

template <typename T>
void PmergeMe::initiateUnsorted(T& empty, char **input) {
	int num;
	for (int i = 0; input[i] != NULL; i++) {
		num = strtol(input[i], NULL, 10);
		empty.push_back(num);	
	}
}

template <typename T>
size_t PmergeMe::binarySearch(T& container, size_t start, size_t end, int target) {
	while (start < end) {
    	size_t middle = (end - start) / 2 + start;
	
		if (target == container.at(middle))
      		return middle;
    	else if (target < container.at(middle))
      		end = middle; //be sure
    	else
      		start = middle + 1;
  }
  return end;
}

template <typename T>
void PmergeMe::printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


#endif