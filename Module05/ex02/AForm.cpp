/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:56 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 18:22:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Standard form"), _isSigned(false), _signGrade(1), _executeGrade(1) {
	
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : \
		_name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& rhs) : \
		_name(rhs._name), _isSigned(false), _signGrade(rhs._signGrade), _executeGrade(rhs._executeGrade) {
}

AForm& AForm::operator=(const AForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

AForm::~AForm() {
	
}

std::string	AForm::getName() const {
	return this->_name;
}

int	AForm::getSignGrade() const {
	return this->_signGrade;
}

int	AForm::getExecuteGrade() const {
	return	this->_executeGrade;
}

bool	AForm::getSignedStatus() const {
	return this->_isSigned;
}

void	AForm::beSigned(Bureaucrat const& brc) {
	if (this->_signGrade >= brc.getGrade() && this->_isSigned != true)
		_isSigned = true;
	else if (_isSigned == true)
		throw FormIsSignedException();
	else
		throw GradeTooLowException();
}

void	AForm::isExecutable(Bureaucrat const & executor) const {
	if (this->_isSigned == false)
		throw FormNotSignedException();
	else if (this->_executeGrade < executor.getGrade())
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