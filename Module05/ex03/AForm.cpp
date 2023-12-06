/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:56 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:33:09 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("Standard form"), isSigned_(false), signGrade_(1), executeGrade_(1) {
	
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : \
		name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
	if (signGrade_ > 150 || executeGrade_ > 150)
		throw GradeTooLowException();
	else if (signGrade_ < 1 || executeGrade_ < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& rhs) : \
		name_(rhs.name_), isSigned_(false), signGrade_(rhs.signGrade_), executeGrade_(rhs.executeGrade_) {
}

AForm& AForm::operator=(const AForm& rhs) {
	this->isSigned_ = rhs.isSigned_;
	return *this;
}

AForm::~AForm() {
	
}

const std::string&	AForm::getName() const {
	return this->name_;
}

int	AForm::getSignGrade() const {
	return this->signGrade_;
}

int	AForm::getExecuteGrade() const {
	return	this->executeGrade_;
}

bool	AForm::getSignedStatus() const {
	return this->isSigned_;
}

void	AForm::beSigned(const Bureaucrat& brc) {
	if (this->signGrade_ >= brc.getGrade() && this->isSigned_ != true)
		isSigned_ = true;
	else if (isSigned_ == true)
		throw FormIsSignedException();
	else
		throw GradeTooLowException();
}

void	AForm::isExecutable(const Bureaucrat& executor) const {
	if (this->isSigned_ == false)
		throw FormNotSignedException();
	else if (this->executeGrade_ < executor.getGrade())
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high for the form.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low for the form.");
}

const char* AForm::FormIsSignedException::what() const throw() {
	return ("Form has been already signed.");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form has no signature.");
}

std::ostream & operator<<(std::ostream & out, const AForm & rhs) {
	out << rhs.getName() << ", signature grade: " << rhs.getSignGrade() << \
	", execution grade: " << rhs.getExecuteGrade() << ", ";
	if (rhs.getSignedStatus() == true)
		out << "SIGNED" << std::endl;
	else
		out << "UNSIGNED" << std::endl;
	return out;
}