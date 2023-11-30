/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 18:11:13 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_executeGrade;
	
	Form& operator=(const Form& rhs);

public:
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form& rhs);
	~Form();
	
	std::string		getName() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;
	bool			getSignedStatus() const;
	void			beSigned(const Bureaucrat& brc);
	
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