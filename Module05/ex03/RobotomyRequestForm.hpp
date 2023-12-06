/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:28:31 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:34:41 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	target_;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	RobotomyRequestForm();
	
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	virtual	~RobotomyRequestForm();

	virtual void	execute(const Bureaucrat& executor) const;

	class InvalidArgumentException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};


#endif