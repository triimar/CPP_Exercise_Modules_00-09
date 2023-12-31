/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 10:19:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "date_utils.hpp"


BitcoinExchange::BitcoinExchange() {}
	
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ) {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ) {
	return *this;
}
	
BitcoinExchange::~BitcoinExchange() {}
	
BitcoinExchange::BitcoinExchange(const std::string& dataBaseFile) {
	std::ifstream file(dataBaseFile.c_str(), std::ios::in);
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
		trimString(date);
		database_.insert(std::make_pair(date, rate));
	}
	file.close();
	return ;
}

std::string& BitcoinExchange::trimString(std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start != std::string::npos) {
        str.erase(0, start);
    } else {
        // if the string is all whitespaces, clear it(just in case)
        str.clear();
        return str;
    }
    size_t end = str.find_last_not_of(" \t\r\n");
    if (end != std::string::npos) {
        str.erase(end + 1);
    }
    return str;
}

double	BitcoinExchange::searchDatabase(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = database_.lower_bound(date);
	if (it == database_.begin())
		return (it->second);
	return (--it)->second;
}

void	BitcoinExchange::returnValue(const std::string& date, const float& value) const {
	double rate = searchDatabase(date);
	std::cout << date << " => " << value << " = " << static_cast<double>(value) * rate << std::endl;
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
		float value;
		if (!std::getline(iss, date, '|') || !(iss >> value)) 
			std::cout << "Error: bad input => " << line << std::endl;
		else {
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (!date_utils::is_valid_date(date))
				std::cout << "Error: bad input => " << date << std::endl;
			else
				returnValue(trimString(date) , value);	
		}
	}
	input.close();
}