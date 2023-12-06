/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 14:55:17 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("Standard form"), isSigned_(false), signGrade_(1), executeGrade_(1) {
	
}

Form::Form(const std::string& name, int signGrade, int executeGrade) : \
		name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
	if (signGrade_ > 150 || executeGrade_ > 150)
		throw GradeTooLowException();
	else if (signGrade_ < 1 || executeGrade_ < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& rhs) : \
		name_(rhs.name_), isSigned_(false), signGrade_(rhs.signGrade_), executeGrade_(rhs.executeGrade_) {
}

Form& Form::operator=(const Form& rhs) {
	this->isSigned_ = rhs.isSigned_;
	return *this;
}

Form::~Form() {
	
}

const std::string&	Form::getName() const {
	return this->name_;
}

int	Form::getSignGrade() const {
	return this->signGrade_;
}

int	Form::getExecuteGrade() const {
	return	this->executeGrade_;
}

bool	Form::getSignedStatus() const {
	return this->isSigned_;
}

void	Form::beSigned(const Bureaucrat& brc) {
	if (this->signGrade_ >= brc.getGrade() && isSigned_ != true)
		isSigned_ = true;
	else if (isSigned_ == true)
		throw FormIsSignedException();
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high for the form.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low for the form.");
}

const char* Form::FormIsSignedException::what() const throw() {
	return ("Form has been already signed");
}

std::ostream & operator<<(std::ostream & out, const Form & rhs) {
	out << rhs.getName() << ", signature grade: " << rhs.getSignGrade() << \
	", execution grade: " << rhs.getExecuteGrade() << ", ";
	if (rhs.getSignedStatus() == true)
		out << "SIGNED" << std::endl;
	else
		out << "UNSIGNED" << std::endl;
	return out;
}