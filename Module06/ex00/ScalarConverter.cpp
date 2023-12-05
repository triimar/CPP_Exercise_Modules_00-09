/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/05 23:11:24 by tmarts           ###   ########.fr       */
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

void ScalarConverter::convert(const std::string& literal) {
	eLiteralType Type;
	
	Type = ScalarParser::getType(literal);
	std::cout << literal << " | Type: " << Type << std::endl;
	
}