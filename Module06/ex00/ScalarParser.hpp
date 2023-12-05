/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:41:01 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/05 22:53:57 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_PARSER_HPP
#define SCALAR_PARSER_HPP

# include <iostream>

enum eLiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PESEUDO
};

class ScalarParser {
	
private:
	ScalarParser();
	~ScalarParser();
	ScalarParser(const ScalarParser& rhs);
	ScalarParser& operator=(const ScalarParser& rhs);
	
public:
	static eLiteralType getType(const std::string& literal);

	class InvalidInputException : public std::exception {
		public:
			virtual const char* what() const throw();
};

};

#endif