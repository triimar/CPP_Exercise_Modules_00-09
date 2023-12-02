/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:00 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/02 19:09:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	std::cout << "--------------------------------------------------" << std::endl;
	PresidentialPardonForm one("Mad kitty");
	Bureaucrat guy("Not allmighty", 20);
	std::cout << one << guy;
	std::cout << "--------------------------------------------------" << std::endl;
	guy.signForm(one);
	guy.executeForm(one);
	std::cout << "--------------------------------------------------" << std::endl;
	Bureaucrat *dude = new Bureaucrat("Boss", 1);
	std::cout << *dude;
	dude->signForm(one);
	dude->executeForm(one);
	std::cout << "--------------------------------------------------" << std::endl;
	AForm *form = new RobotomyRequestForm("Ultron");
	std::cout << *form;
	dude->signForm(*form);
	guy.executeForm(*form);
	std::cout << "--------------------------------------------------" << std::endl;
	ShrubberyCreationForm *greenery = new ShrubberyCreationForm("42");
	std::cout << *greenery;
	guy.signForm(*greenery);
	dude->executeForm(*greenery);
	delete dude;
	delete form;
	delete greenery;
}