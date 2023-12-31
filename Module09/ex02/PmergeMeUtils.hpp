/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:12:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 09:30:05 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEUTILS_HPP
#define PMERGEMEUTILS_HPP
#include <limits>
#include <cstdlib>

namespace PmergeMeUtils
{
	bool	inputIsValid(char **input);
	size_t	getNextJacobstahl(size_t prev, size_t current);
}

#endif
