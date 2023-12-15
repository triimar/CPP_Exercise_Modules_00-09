/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:21:26 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/15 20:40:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>


Base* generate(void) {
	std::srand(static_cast<unsigned>(std::time(0)));
	int i = std::rand() % 3;
	if (i == 0)
	{
		std::cout << "Randomy generated A" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Randomy generated B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Randomy generated C" << std::endl;
		return new C;
	}
}
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "The actual type of the object pointed to is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The actual type of the object pointed to is B" << std::endl;
	else if  (dynamic_cast<C *>(p))
		std::cout << "The actual type of the object pointed to is C" << std::endl;
	else
		std::cout << "Error! Failed to identify the type of the object" << std::endl;
}
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p) {
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "The actual type of the object referenced is A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "The actual type of the object referenced is B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "The actual type of the object referenced to is C" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cerr << e.what() << std::endl;
			}
			
		}
		
	}
}
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.
int main()
{
	Base* one = generate();
	identify(one);
	identify(*one);
	delete one;
}