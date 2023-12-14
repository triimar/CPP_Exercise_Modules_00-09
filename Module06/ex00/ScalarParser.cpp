/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:40:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/14 20:48:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarParser.hpp"
#include <sstream>

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
	std::istringstream intStream(literal);
	int intVal;
	intStream >> intVal;
	if (!intStream.fail() && intStream.eof())
		return INT;
	if (literal.length() == 1)
		return CHAR;
	if (literal[literal.length() - 1] == 'f' && literal != "-inf" && literal != "+inf")
	{
		std::string modifiedStr = literal.substr(0, literal.length() - 1);
		std::istringstream floatStream(modifiedStr);
		float floatVal;
		floatStream >> floatVal;
		if (!floatStream.fail() && floatStream.eof())
			return FLOAT;
		else
			throw InvalidInputException();
	}
	std::istringstream doubleStream(literal);
	double doubleVal;
	doubleStream >> doubleVal;
	if (!doubleStream.fail() && doubleStream.eof())
		return DOUBLE;
	else
		throw InvalidInputException();
}


const char* ScalarParser::InvalidInputException::what() const throw() {
	return "Input invalid!";
}