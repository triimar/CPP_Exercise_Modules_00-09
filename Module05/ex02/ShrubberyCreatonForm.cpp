/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreatonForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:27:18 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 20:26:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("") {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}


ShrubberyCeationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : \
	AForm("Shrubbery Creation Form", 145, 137) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	
}