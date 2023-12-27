/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:12:26 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/27 19:27:34 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cctype> //for std::isdigit()
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <limits>


class RPN {
private:
	std::stack<int> 	intStack_;
	std::string			input_;

	void executeOperation(const std::string::const_iterator& it);

public:
	RPN();
	~RPN();
	RPN(const RPN& rhs);
	RPN(std::string input);
	const RPN& operator=(const RPN& rhs);

	void solve();	
};

#endif