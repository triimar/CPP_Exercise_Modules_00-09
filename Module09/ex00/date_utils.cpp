/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:37:41 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/26 14:39:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "date_utils.hpp"

bool date_utils::is_valid_date(std::string date) {
	int		year, month, day;
	char	dash, dash2;

	std::istringstream dateString(date);
	dateString >> year >> dash >> month >> dash2 >> day;
	if (!dateString || dash != '-' || dash2 != '-')
		return false;
	if (year < 1 || year > 2024)
		return false;
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return false;
	if (month == 2 && day > 28) {
		if (day > 29 || (day == 29 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0))))
			return false;
	}
	return true;
}
		
	

