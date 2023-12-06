/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/06 15:46:14 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();
	
	AForm* makeForm(const std::string& formName, const std::string& target);
	
	class NoSuchFormException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif
