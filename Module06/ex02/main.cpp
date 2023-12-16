/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:21:26 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/16 19:10:36 by tmarts           ###   ########.fr       */
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

//when the cast is impossible and conversion fails - the dynmic_cast returns NULL
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

//reference by definition cannot return a NULL pointer, 
//so instead exception gets thrown if dynamic cast fails.
void identify(Base& p) {
	try
	{
		A& pt = dynamic_cast<A &>(p);
		(void)pt;
		std::cout << "The actual type of the object referenced is A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			B& pt = dynamic_cast<B &>(p);
			(void)pt;
			std::cout << "The actual type of the object referenced is B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				C& pt = dynamic_cast<C &>(p);
				(void)pt;
				std::cout << "The actual type of the object referenced to is C" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

int main()
{
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
}