/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 14:23:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Mr. Nobody"), grade_(150) {
	std::cout << "====default constructor " << name_ << "====" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
	std::cout <<  "====constructor " << name_ << "====" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : \
			name_(rhs.name_), grade_(rhs.grade_) {
	std::cout << "====copy constructor " << name_ << "====" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "====destructor " << name_ << "====" << std::endl;
}


Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		this->grade_ = rhs.grade_;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->name_;
}

int	Bureaucrat::getGrade() const {
	return this->grade_;
}

void	Bureaucrat::incrementGrade() {
	if (grade_ - 1 < 1)
		throw GradeTooHighException();
	grade_--;
}

void	Bureaucrat::decrementGrade() {
	if (grade_ + 1 > 150)
		throw GradeTooLowException();
	grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade is too low.");
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat& rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}
