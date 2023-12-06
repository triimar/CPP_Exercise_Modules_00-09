/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 14:30:14 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat One;
	Bureaucrat Two = One;
	std::cout << One;
	std::cout << Two;
	std::cout << "--------------INCREMENT-DECREMENT--EXCEPTIONS--------" << std::endl;
	try
	{
		One.decrementGrade();
		while (One.getGrade() >= 1)
			One.incrementGrade();
		// One.incrementGrade();
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
		while (Two.getGrade() >= 0)
			Two.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{	
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}	
	catch (const Bureaucrat::GradeTooHighException& e)
	{	
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << Two;
	std::cout << "---------INSTANTIATING--EXCEPTIONS--------------------" << std::endl;
	try
	{
		Bureaucrat Four("Harold", 5);
		std::cout << Four;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;	
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Five("Donald", 255);
		std::cout << Five;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Six("Johannes", -45);
		std::cout << Six;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// std::cout << "---------------------CAUSING AN ERROR--------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat Seven("Albert", 0);
	// }
	// catch (const Bureaucrat::GradeTooLowException &e)
	// {
	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
	// }
	return 0;
}