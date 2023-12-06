/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:15:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

private:
	const std::string	name_;
	bool				isSigned_;
	const int			signGrade_;
	const int			executeGrade_;
	
	Form& operator=(const Form& rhs);

public:
	Form();
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& rhs);
	~Form();
	
	const std::string&	getName() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	bool				getSignedStatus() const;
	
	void				beSigned(const Bureaucrat& brc);
	
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class FormIsSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & out, const Form& rhs);

# endif