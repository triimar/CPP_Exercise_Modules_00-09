/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:12:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 04:27:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEUTILS_HPP
#define PMERGEMEUTILS_HPP
#include <limits>
#include <cstdlib>
#include <iostream>


namespace PmergeMeUtils
{
	bool inputIsValid(char **input);
	size_t getNextJacobstahl(size_t prev, size_t current);
	
	template <typename T>
	// template <typename T, typename I>
	size_t binarySearch(T& container, size_t start, size_t end, int target, size_t chunk);
	
	template <typename It>
	It getIndexIt(It start, size_t index, size_t groupSize);

}

template <typename It>
It PmergeMeUtils::getIndexIt(It start, size_t index, size_t groupSize) {
	// std::cout << "in get index: " << index << "|" << groupSize << std::endl;
	It iterator = start + (index * groupSize);
	// std::cout << "in get index: Iterator " << *iterator << std::endl;
	return(iterator);
}

template <typename T>
size_t PmergeMeUtils::binarySearch(T& container, size_t start, size_t end, int target, size_t chunk) {
	while (start < end) {
    	size_t middle = (end - start) / 2 + start;
		// T container::iterator midIt == PmergemeUtils::getIndexIt(container.begin(), middle + 1, chunk);
		// --midIt;
		if (target == *(PmergeMeUtils::getIndexIt(container.begin(), middle + 1, chunk) - 1))
      		return middle;
    	else if (target < *(PmergeMeUtils::getIndexIt(container.begin(), middle + 1, chunk) - 1))
      		end = middle; //be sure
		// if (target == container.at(middle))
      	// 	return middle;
    	// else if (target < container.at(middle))
      	// 	end = middle - 1;
    	else
      		start = middle + 1;
  }
  return end;
}

#endif
