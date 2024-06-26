/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:54 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:48:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
	
}

Intern::~Intern() {
	
}

Intern::Intern(const Intern&) {
}

Intern& 	Intern::operator=(const Intern&) {
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	const std::string Forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int		formIndex;
	AForm	*newForm = NULL;
	
	formIndex = -1;
	while (++formIndex < 3)
	{
		if (Forms[formIndex] == formName)
			break;
	}
	switch (formIndex)
	{
	case 0:
		newForm = new PresidentialPardonForm(target);
		break;
	case 1:
		newForm = new RobotomyRequestForm(target);
		break;
	case 2:
		newForm = new ShrubberyCreationForm(target);
		break;
	default:
		throw NoSuchFormException();
	}
	std::cout << "Intern created " << newForm->getName() << "." << std::endl;
	return(newForm);
}

const char* Intern::NoSuchFormException::what() const throw() {
	return "No such form exists.";
}