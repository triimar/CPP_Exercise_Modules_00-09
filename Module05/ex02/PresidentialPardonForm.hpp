/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:29:58 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/30 21:12:05 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENITAL_PARDON_FORM_HPP
#define PRESIDENITAL_PARDON_FORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
private:
	std::string	_target;
	
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	PresidentialPardonForm();
	
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	virtual	~PresidentialPardonForm();

	virtual void	execute(const Bureaucrat &executor) const;
};

#endif