/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/04 17:13:15 by tmarts           ###   ########.fr       */
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
	
	AForm* makeForm(std::string formName, std::string target);
	
	class NoSuchFormException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif
