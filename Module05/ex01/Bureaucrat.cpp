/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 14:52:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name_("Mr. Nobody"), grade_(150) {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name_(rhs.name_), grade_(rhs.grade_) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		this->grade_ = rhs.grade_;
	return *this;
}

const std::string& 	Bureaucrat::getName() const {
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

void	Bureaucrat::signForm(Form& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << this->name_ << " signed the " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name_ << " could not sign the form " << form.getName() \
		<< ". Reason: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Suggested grade is too high for a bureaucrat.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Suggested grade is too low for a bureaucrat.");
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat& rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}
