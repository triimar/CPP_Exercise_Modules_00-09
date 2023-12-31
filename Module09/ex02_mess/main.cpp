/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:06 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/30 23:41:11 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"




int main(int argc, char *argv[]){
	if (argc == 1) {
		std::cout << "Error: input is expected." << std::endl;
		return 1;
	}
	if (!PmergeMeUtils::inputIsValid(++argv)) {
		std::cout << "Error: invalid input. Positive integer sequence expected." << std::endl;
		return 1;
	}
	std::vector<int> numList;
	PmergeMe::initiateUnsortedVec(numList, argv);
	std::cout << "Data is sorted? " << std::boolalpha << std::is_sorted(numList.begin(), numList.end()) << std::endl;
	PmergeMe::printContainer(numList);
	PmergeMe::sortVec(numList);
	std::cout << "FINAL RESULT IN MAIN: ";
	PmergeMe::printContainer(numList);
	// return 0;
	std::cout << PmergeMeUtils::getNextJacobstahl(1, 3) << std::endl;
	
	// std::vector<int> original;
	// original.push_back(5);
	// original.push_back(9);
	// original.push_back(22);
	// original.push_back(1);
	// std::cout << "original: ";
	// PmergeMe::printContainer(original);
	
	// std::vector<std::vector<int>::iterator> thingy;
	// // std::vector<std::vector<int>::iterator> smaller;
    // // // Fill thmake ree iteratorVector with iterators to the elements in originalVector
	// // int i = 0;
    // for ( std::vector<int>::iterator it = original.begin(); it != original.end(); ++it) {
    //     thingy.push_back(it);
	// // 	if (i % 2 == 0)
	// // 		smaller.push_back(it);
	// // 	i++;
    // }
	// // for (std::vector<std::vector<int>::iterator>::iterator it = smaller.begin(); it != smaller.end(); ++it)
	// // 	std::cout << **it << " ";
	// // std::cout << std::endl;
	// // // PmergeMe::swapChunks(smaller[0], smaller[1], original.end());
	// // PmergeMe::swapChunks(smaller[0], smaller[3], original.end());
	
	// original.insert(thingy[0], *thingy[3]);
	// thingy.insert(thingy.begin(), thingy[3]);
	// // thingy.erase(thingy.end() - 1);
	// // original.erase(thingy[3]);
	// // std::move_backward(thingy[2], thingy[3], thingy[0]);
	// std::cout << "original: ";
	// PmergeMe::printContainer(original);
	// std::cout << "iterator vector: ";
	// for (std::vector<std::vector<int>::iterator>::iterator it = thingy.begin(); it != thingy.end(); ++it)
	// 	std::cout << **it << " ";
	std::cout << std::endl;
	return 0;
}