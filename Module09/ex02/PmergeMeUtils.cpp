/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:15:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 09:51:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeUtils.hpp"
#include <iostream>

bool PmergeMeUtils::inputIsValid(char **input)
{
	if (*input == NULL || *(input + 1) == NULL) {
		return false;
	}
	long int num;
	char *end;
	for (size_t i = 0; input[i] != NULL; i++) {
		num = strtol(input[i], &end, 10);
		if (*end != 0)
			return false;
		if (num < 0 || num > std::numeric_limits<int>::max())
			return false;
	}
	return (true);
}

size_t PmergeMeUtils::getNextJacobstahl(size_t prev, size_t current) {
	return (current + 2 * prev);
}