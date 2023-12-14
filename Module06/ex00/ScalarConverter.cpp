/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/14 21:03:05 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& ) {
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) {
	return *this;
}

void ScalarConverter::convertChar(const std::string& literal) {
	char c = literal[0];
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: " << c << std::endl \
			<< "int: " << static_cast<int>(c) << std::endl \
			<< "float: " << static_cast<float>(c) << "f" << std::endl \
			<< "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal) {
	std::istringstream intStream(literal);
	int i;
	intStream >> i;
	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		if (i < 32 || i == 127)
			std::cout << "char: not displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl \
			<< "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal) {
	std::string str = literal.substr(0, literal.length() - 1);
	std::istringstream floatStream(str);
	float f;
	floatStream >> f;
	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		if (f < 32 || f == 127)
			std::cout << "char: not displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if  (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl \
			<< "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& literal) {
	std::istringstream doubleStream(literal);
	double d;
	doubleStream >> d;
	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		if (d < 32 || d == 127)
			std::cout << "char: not displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (literal != "-inf" && literal != "+inf" && (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	
	
}

void ScalarConverter::convert(const std::string& literal) {

	switch (ScalarParser::getType(literal))
	{
	case CHAR:
		convertChar(literal);
		break;
	case INT:
		convertInt(literal);
		break;
	case FLOAT:
		convertFloat(literal);
		break;
	default:
		convertDouble(literal);
		break;
	}
}