/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/04 17:05:44 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {


private:
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_executeGrade;
	
	AForm& operator=(const AForm& rhs);
	AForm();

protected:
	void	isExecutable(Bureaucrat const& executor) const;

public:
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm& rhs);
	virtual ~AForm();
	
	std::string		getName() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;
	bool			getSignedStatus() const;
	
	void			beSigned(Bureaucrat const& brc);
	virtual void	execute(Bureaucrat const& executor) const = 0;
	
	class FormIsSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class InvalidArgumentException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & out, const AForm& rhs);

# endif