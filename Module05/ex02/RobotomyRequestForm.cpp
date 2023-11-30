/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:07 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 20:53:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
# include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 75, 45), _target("") {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 75, 45), _target(target) {
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : \
	AForm("Robotomy Request Form", 75, 45) {
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	
}

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.