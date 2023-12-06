/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:00 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:49:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Intern	invisibleCod = Intern();
	AForm* form = NULL;
	Bureaucrat guy("Not allmighty", 20);
	Bureaucrat *dude = new Bureaucrat("Boss", 1);
	std::cout << guy << *dude;
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		form = invisibleCod.makeForm("presidential pardon", "Angry kitten");
		std::cout << *form;
		guy.signForm(*form);
		guy.executeForm(*form);
		dude->signForm(*form);
		dude->executeForm(*form);
		delete form;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception was caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		form = invisibleCod.makeForm("Give a vacation", "everybody");
		std::cout << *form;
		guy.signForm(*form);
		dude->executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception was caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		form = invisibleCod.makeForm("robotomy request", "Ultron");
		std::cout << *form;
		dude->signForm(*form);
		guy.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		form = invisibleCod.makeForm("shrubbery creation", "42");
		std::cout << *form;
		guy.signForm(*form);
		dude->executeForm(*form);
		delete form;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception was caught: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;

	delete dude;
}