/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/26 21:27:40 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat Herr("Müller", 99);
	Bureaucrat Frau("Bauer", 2);
	Form One;
	Form Two("C211", 5, 8);
	std::cout << One << Two;
	std::cout << "-----TRYING TO INSTANTIATE UNSUTIABLE VALUES-----" << std::endl;
	try
	{
		Form Three("Too low Sign Grade", 255, 8);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exeption was caught: " << e.what() << '\n';
	}
	try
	{
		Form Four("Too high Execution Grade", 8, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exeption was caught: " << e.what() << '\n';
	}
	std::cout << "-------------------SIGNING-----------------------" << std::endl;
	try
	{
		Two.beSigned(Frau);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Looks like an error: " << e.what() << std::endl;
	}
	std::cout << Two;
	try
	{
		Herr.signForm(Two);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Looks like an error: " << e.what() << std::endl;
	}
	try
	{
		Frau.signForm(One);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Looks like an error: " << e.what() << std::endl;
	}
	Form Five("A112", 10, 2);
	try
	{
		Frau.signForm(Five);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------UPDATED FORMS----------------------" << std::endl;
	std::cout << One << Two << Five;
	return 0;
}