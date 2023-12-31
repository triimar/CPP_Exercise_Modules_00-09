/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:09:47 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/31 10:09:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip> //for std::setprecison()
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string,double> database_;
	
	BitcoinExchange(const BitcoinExchange& rhs);
	const BitcoinExchange& operator=(const BitcoinExchange& rhs);
	BitcoinExchange();
	
	std::string& trimString(std::string& str);	
	double	searchDatabase(const std::string& date) const;
	void	returnValue(const std::string& date, const float& value) const;
		
public:
	BitcoinExchange(const std::string& dataBaseFile);
	~BitcoinExchange();
	
	void	run(const std::string& infile);
};

#endif
