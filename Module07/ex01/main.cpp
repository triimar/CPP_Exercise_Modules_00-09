/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:54:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 17:35:45 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void add(int& i)
{
	i++;
}

int main(void)
{
	int arr[] = {1, 4, 6};
	iter(arr, 3, print<int>);
	std::cout << std::endl;
	iter(arr, 3, add);
	iter(arr, 3, print<int>);
	std::cout << std::endl;
	
	std::string str = "hello";
	iter(str.c_str(), str.length(), print<const char>);
	std::cout << std::endl;
	
	std::string strs[] = {"you", "are", "here"};
	iter(strs, 3, print<std::string>);
	std::cout << std::endl;
	
	
}