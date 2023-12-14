/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:31 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/14 21:01:43 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <sstream>
#include "ScalarParser.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	static void convertChar(const std::string& literal);
	static void convertInt(const std::string& literal);
	static void convertFloat(const std::string& literal);
	static void convertDouble(const std::string& literal);
	
public:
	static void convert(const std::string& literal);
};

#endif