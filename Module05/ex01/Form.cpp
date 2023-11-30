/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 18:10:58 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Standard form"), _isSigned(false), _signGrade(1), _executeGrade(1) {
	
}

Form::Form(std::string name, int signGrade, int executeGrade) : \
		_name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& rhs) : \
		_name(rhs._name), _isSigned(false), _signGrade(rhs._signGrade), _executeGrade(rhs._executeGrade) {
}

Form& Form::operator=(const Form& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form() {
	
}

std::string	Form::getName() const {
	return this->_name;
}

int	Form::getSignGrade() const {
	return this->_signGrade;
}

int	Form::getExecuteGrade() const {
	return	this->_executeGrade;
}

bool	Form::getSignedStatus() const {
	return this->_isSigned;
}

void	Form::beSigned(const Bureaucrat& brc) {
	if (this->_signGrade >= brc.getGrade() && _isSigned != true)
		_isSigned = true;
	else if (_isSigned == true)
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