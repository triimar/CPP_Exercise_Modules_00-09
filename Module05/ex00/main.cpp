/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/20 20:52:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat One;
	Bureaucrat Two = One;
	Bureaucrat Three(Two);
	std::cout << One;
	std::cout << Two;
	std::cout << Three;

	std::cout << "---------------------------------------------------" << std::endl;
	Bureaucrat *dude = new Bureaucrat("Joe", 2);
	std::cout << *dude;
	delete dude;
	std::cout << "---------------------------------------------------" << std::endl;
	try
	{
		One.decrementGrade();
		One.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{	
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}	
	catch (const Bureaucrat::GradeTooHighException &e)
	{	
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << One;
	try
	{
		Bureaucrat Four("Harold", -5);

	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
}