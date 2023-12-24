/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/24 18:22:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}
	
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ) {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ) {
	return *this;
}
	
BitcoinExchange::~BitcoinExchange() {}
	
BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
	std::ifstream file(dataFile.c_str(), std::ios::in);
	if (!file)
		throw std::runtime_error("Database creation failure. Could not open the database file.");
	
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Database creation failure. Header (\"date,exchange_rate\") not found.");
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		double rate;
		if ( !std::getline(iss, date, ',') || !(iss >> rate))
			throw std::runtime_error("Database creation failure. Bad input: " + line);
		iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		database_.insert(std::make_pair(date, rate));
	}
	// std::cout << std::fixed << std::setprecision(4);
	// std::map<std::string, double>::iterator it = database_.begin();
	// while (it != database_.end()) {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// 	it++;
	// }
	file.close();
	return ;
}

void BitcoinExchange::run(const std::string& infile) {
	std::ifstream input(infile.c_str(), std::ios::in);
	if (!input)
		throw std::runtime_error("Could not open file.");
	std::string line;
	std::getline(input, line);
	if (line != "date | value")
		throw std::runtime_error("Header (\"date | value\") not found in file.");
	std::cout << "date | value" << std::endl;
	while (std::getline(input, line)) {
		std::istringstream iss(line);
		std::string date;
		double value;
		if ( !std::getline(iss, date, '|') || !(iss >> value)){
			std::cout << "Error: bad input => " << line << std::endl;
		}
		else
			std::cout << date << "_______" << value << std::endl;
	}
	input.close();
}