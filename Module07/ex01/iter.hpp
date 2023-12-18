/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:54:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 17:25:12 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include<cstddef>
#include <iostream>

// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.
// Turn in a main.cpp file that contains your tests. Provide enough code to generate a
// test executable.
// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.

template <typename T>
void print(T& i)
{
	std::cout << i << " ";
}

// template <typename T>
// void	iter(T *array, size_t len, void (*f)(T& elem)){
// 	if (array == NULL || f == NULL)
// 		return ;
// 	for(size_t i = 0; i < len; i++)
// 		f(array[i]);
// }

template <typename T, typename Func>
void	iter(T *array, const size_t len, Func f){
	if (array == NULL || f == NULL)
		return ;
	for(size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif