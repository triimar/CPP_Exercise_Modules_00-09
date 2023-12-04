/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:27:18 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/04 17:20:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : \
					AForm("Shrubbery Creation Form", 145, 137), _target("") {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
					AForm("Shrubbery Creation Form", 145, 137) {
	if (target.empty())
		throw InvalidArgumentException();
	_target = target;
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : \
	AForm("Shrubbery Creation Form", 145, 137), _target(rhs._target) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	this->isExecutable(executor);
	std::ofstream outf(_target + "_shrubbery", std::ios::out | std::ios::app);
	if (outf.is_open()) {
		outf << "				oo,ooooooo           *\n\
   *  ,ooo \\-*ooooooo\n\
         ;oooooo*o   _oooo/* ^  oo \n\
     ,*oooo\\oo  * * _.*oooooo.oooooo *\n\
        ^ oo*oo,  ,ooooo*(    ooooo\n\
*      %^     ,*ooo )\\|,oooo,_           *\n\
             *o   \\/ #.-*00*\n\
                  ./ ,/ *%, ^\n\
   _______________/ #/_____________\n" << std::endl;
   		outf.close();
		std::cout << "@ Shrubbery has been successfully planted (see location) @" << std::endl;
	}
  	else 
  		std::cout << "Unable to open shrubbery file" << std::endl;
}

const char* ShrubberyCreationForm::InvalidArgumentException::what() const throw() {
	return "For the form to be valid, it requires a target. Target cannot be empty.";
}