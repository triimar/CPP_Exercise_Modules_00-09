/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:18:14 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 02:47:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include "PmergeMeUtils.hpp"

class PmergeMe
{
private:
	
	static void FordJohnson(std::vector<std::vector<int>::iterator>& v, std::vector<int>::iterator& end, size_t chunk);
	
	template <typename T, typename It>
	static void insertChunk(T& container, It dst, It src, size_t chunk);
	// template <typename T, typename It>
	// static void insertChunkRev(T& container, It dst, It src, size_t chunk);
	PmergeMe();
	~PmergeMe();
	
public:
	
	static void initiateUnsortedVec(std::vector<int>& empty, char **input);
	static void sortVec(std::vector<int>& unsorted);

	template <typename It>
	static void swapChunks(It first1, It second1, It end);
	
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

template <typename T, typename It>
void PmergeMe::insertChunk(T& container, It dst, It src, size_t chunk) {
	// std::cout << "CHUNK " << chunk << std::endl;
	for (size_t i = 0; i < chunk; i++) {
  		dst = container.insert(dst, *src);
		// PmergeMe::printContainer(container);
		// dst++;
		src++;
	}
	// std::cout << *dst;
	// std::cout << *src;
	// std::cout << chunk;
	// container.insert(dst, src, src + chunk);
}

// template <typename T>
// T binarySearch(int& target, T start, T end, size_t chunk) {
//   size_t size = (end - start) / chunk;
//   if (size < 1) return end;
//   T mid = start + (size / 2) * chunk;
//   if (*mid < target) return binarySearch(target, mid + chunk, end, chunk);
//   return binarySearch(target, start, mid, chunk);
// }



// template <typename T, typename It>
// void PmergeMe::insertChunkRev(T& container, It dst, It src, size_t chunk) {
// 	// std::cout << "CHUNK " << chunk << std::endl;
// 	for (size_t i = 0; i < chunk; i++) {
//   		dst = container.insert(dst, *src);
// 		// PmergeMe::printContainer(container);
// 		// dst++;
// 		std::cout << *src << std::endl;
// 		--src;
// 	}
// 	// std::cout << *dst;
// 	// std::cout << *src;
// 	// std::cout << chunk;
// 	// container.insert(dst, src, src + chunk);
// }

// std::vector<int>& getIterToIndex()




#endif