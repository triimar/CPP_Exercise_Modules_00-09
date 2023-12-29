/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:18:14 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/29 21:51:41 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <iostream>
#include <algorithm>

class PmergeMe
{
private:
	// char **input_;
	// std::vector<int>	unsortedVec_;
	// size_t				size_;			
	static void FordJohnson(std::vector<std::vector<int>::iterator>& v, std::vector<int>::iterator& end, size_t chunk);
;public:
	PmergeMe();
	~PmergeMe();
	
	static void initiateUnsortedVec(std::vector<int>& empty, char **input);
	static void sortVec(std::vector<int>& unsorted);

	template <typename ForwardIt>
	static void swapChunks(ForwardIt first1, ForwardIt second1, ForwardIt end);
	
	template <typename T>
	static void printContainer(const T& container);
	
};

// member function templates

template <typename T>
void PmergeMe::printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//Swaps two consecutive chunks of integers. Should not be used if the chunks are not the same size.
template <typename It>
void PmergeMe::swapChunks(It first1, It second1, It end) {
	It first2 = second1;
    while (first1 != first2 && second1 != end) {
        std::iter_swap(first1++, second1++);
    }
}

// template <typename T, typename It>
// void PmergeMe::insertChunk(const It& chunkStart, T& dstCont, T& stcCont, int chunk) {
	
// }

#endif