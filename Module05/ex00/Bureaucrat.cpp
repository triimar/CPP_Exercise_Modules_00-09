/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/20 20:42:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Nobody"), _grade(150) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : \
			_name(rhs._name), _grade(rhs._grade) {

}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}
Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

std::string 	Bureaucrat::getName() const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void			Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Suggested grade is too high for a bureaucrat.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Suggested grade is too low for a bureaucrat.");
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}
