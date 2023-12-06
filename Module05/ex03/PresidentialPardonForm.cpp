/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 16:21:18 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) , target_("") {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5) {
	if (target.empty())
		throw InvalidArgumentException();
	target_ = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : \
	AForm("Presidential Pardon Form", 25, 5) , target_(rhs.target_) {	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs)
	{
		this->target_ = rhs.target_;
		AForm::operator=(rhs);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->isExecutable(executor);
	std::cout << "\\(^O^)/ " << target_ << " has been pardoned by Zaphod Beeblebrox. " << "\\(^O^)/"<< std::endl;
}

const char* PresidentialPardonForm::InvalidArgumentException::what() const throw() {
	return "For the form to be valid, it requires a target. Target cannot be empty.";
}