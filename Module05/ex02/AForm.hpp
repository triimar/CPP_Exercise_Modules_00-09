/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 16:25:16 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {

private:
	const std::string	name_;
	bool				isSigned_;
	const int			signGrade_;
	const int			executeGrade_;
	
	AForm();

protected:
	AForm& operator=(const AForm& rhs);
	void	isExecutable(Bureaucrat const& executor) const;

public:
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& rhs);
	virtual ~AForm();
	
	const std::string&	getName() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	bool				getSignedStatus() const;
	
	void			beSigned(const Bureaucrat& brc);
	virtual void	execute(const Bureaucrat& executor) const = 0;
	
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

};

std::ostream & operator<<(std::ostream & out, const AForm& rhs);

# endif