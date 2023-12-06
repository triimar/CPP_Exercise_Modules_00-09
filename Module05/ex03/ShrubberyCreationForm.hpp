/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:27:28 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:35:18 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	target_;
	
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm();
	
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	virtual	~ShrubberyCreationForm();

	virtual void	execute(const Bureaucrat& executor) const;
	
	class InvalidArgumentException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif