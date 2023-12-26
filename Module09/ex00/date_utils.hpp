/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:37:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/26 14:08:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_UTILS_HPP
#define DATE_UTILS_HPP

#include <string>
#include <sstream>

namespace date_utils
{
	bool is_valid_date(std::string date);
}

#endif