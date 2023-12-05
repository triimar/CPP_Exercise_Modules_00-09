/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:40:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/05 23:09:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarParser.hpp"

ScalarParser::ScalarParser() {
}

ScalarParser::~ScalarParser() {
}

ScalarParser::ScalarParser(const ScalarParser& ) {
	
}

ScalarParser& ScalarParser::operator=(const ScalarParser& ) {
	return *this;
}

eLiteralType ScalarParser::getType(const std::string& literal) {
	if (literal.empty())
		throw InvalidInputException();
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	return INT;
	
}


const char* ScalarParser::InvalidInputException::what() const throw() {
	return "Input invalid!";
}