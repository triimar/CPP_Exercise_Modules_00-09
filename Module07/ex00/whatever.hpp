/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:50:58 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 14:59:16 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T_SW>
void swap(T_SW& x, T_SW& y) {
	T_SW tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template<typename T_MX>
const T_MX&	 max(const T_MX& x, const T_MX& y) {
	return (x > y ? x : y);
}

template<typename T_MN>
const T_MN&	min(const T_MN& x, const T_MN& y) {
	return (x < y ? x : y);
}

#endif

// Implement the following function templates:
// • swap: Swaps the values of two given arguments. Does not return anything.
// • min: Compares the two values passed in its arguments and returns the smallest
// one. If the two of them are equal, then it returns the second one.
// • max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
// These functions can be called with any type of argument. The only requirement is
// that the two arguments must have the same type and must support all the comparison
// operators.