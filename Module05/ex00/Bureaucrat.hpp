/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/26 18:07:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat {

private:
	std::string const	_name;
	int					_grade;		
	
	Bureaucrat& operator=(const Bureaucrat& rhs);

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	~Bureaucrat();
	
	std::string 	getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();

	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& outputStr, const Bureaucrat& a);

#endif