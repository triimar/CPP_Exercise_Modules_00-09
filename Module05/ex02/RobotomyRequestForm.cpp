/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:07 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 16:20:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 75, 45), target_("") {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : \
					AForm("Robotomy Request Form", 75, 45) {
	if (target.empty())
		throw InvalidArgumentException();
	target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : \
	AForm("Robotomy Request Form", 75, 45), target_(rhs.target_) {
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs)
	{
		this->target_ = rhs.target_;
		AForm::operator=(rhs);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->isExecutable(executor);
	std::srand(static_cast<unsigned>(std::time(0)));
	std::cout << "|| GrrrrrBrrrZRRRRR ... GrrrrrBRRRRZrrrrr ... GRRRRBrrrZrrrrr               ||" << std::endl;
	if (std::rand() % 2)
		std::cout << "|| " <<target_ << " has been succesfully robotomyzed.                                 ||" << std::endl;
	else
		std::cout << "|| Complications during robotomy process .. ... Robomtomy of " << target_ << " FAILED. ||" << std::endl;
}

const char* RobotomyRequestForm::InvalidArgumentException::what() const throw() {
	return "For the form to be valid, it requires a target. Target cannot be empty.";
}