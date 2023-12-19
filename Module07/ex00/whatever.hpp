/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:50:58 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/19 17:44:02 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// swap: Swaps the values of two given arguments. Does not return anything.
template<typename T_SW>
void swap(T_SW& x, T_SW& y) {
	T_SW tmp;
	tmp = x;
	x = y;
	y = tmp;
}

// max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template<typename T_MX>
const T_MX&	 max(const T_MX& x, const T_MX& y) {
	return (x > y ? x : y);
}

// min: Compares the two values passed in its arguments and returns the smallest
// one. If the two of them are equal, then it returns the second one.
template<typename T_MN>
const T_MN&	min(const T_MN& x, const T_MN& y) {
	return (x < y ? x : y);
}

#endif
