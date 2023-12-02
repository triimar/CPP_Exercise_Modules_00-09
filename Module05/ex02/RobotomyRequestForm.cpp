/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:07 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/02 17:33:50 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 75, 45), _target("") {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
					AForm("Robotomy Request Form", 75, 45), _target(target) {	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : \
	AForm("Robotomy Request Form", 75, 45), _target(rhs._target) {
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	this->isExecutable(executor);
	std::srand(static_cast<unsigned>(std::time(0)));
	std::cout << "|| GrrrrrBrrrZRRRRR ... GrrrrrBRRRRZrrrrr ... GRRRRBrrrZrrrrr               ||" << std::endl;
	if (std::rand() % 2)
		std::cout << "|| " <<_target << " has been succesfully robotomyzed.                                 ||" << std::endl;
	else
		std::cout << "|| Complications during robotomy process .. ... Robomtomy of " << _target << " FAILED. ||" << std::endl;
}

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.