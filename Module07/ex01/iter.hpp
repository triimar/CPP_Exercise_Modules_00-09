/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:54:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/19 17:47:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>
# include <iostream>


template <typename T>
void print(T& i)
{
	std::cout << i << " ";
}

/* Function pointer (void (*f)(T& elem) ) can be used instead of <typename> Func'
but this version is more generalized an more "CPP-like"*/
template <typename T, typename Func>
void	iter(T *array, const size_t len, Func f){
	if (array == NULL || f == NULL)
		return ;
	for(size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif