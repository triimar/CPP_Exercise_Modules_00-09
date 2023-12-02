/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/02 17:07:31 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) , _target("") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : \
	AForm("Presidential Pardon Form", 25, 5) , _target(rhs._target) {	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	this->isExecutable(executor);
	std::cout << "\\(^O^)/ " << _target << " has been pardoned by Zaphod Beeblebrox. " << "\\(^O^)/"<< std::endl;
}