/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:28:31 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 20:30:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	RobotomyRequestForm();
	
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	virtual	~RobotomyRequestForm();

	virtual void	execute(const Bureaucrat &executor) const;
};


#endif