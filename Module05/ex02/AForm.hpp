/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:29:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/25 19:04:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>

class	AForm {

private:
	std::string const	_name;
	bool				_isSigned;
	unsigned int const	_signGrade;
	unsigned int const	_executeGrade;
	
	AForm& operator=(const AForm& rhs);

public:
	AForm();
	AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);
	AForm(const AForm& rhs);
	virtual ~AForm();
	
	std::string		getName() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecuteGrade() const;
	bool			getSignedStatus() const;
	
	virtual void	beSigned(const Bureaucrat brc);
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