/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:43:36 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/21 21:21:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int i) {
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::runtime_error("integer not found in the container.");
	return it;
}

#endif