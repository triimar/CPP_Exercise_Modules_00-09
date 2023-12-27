/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:12:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/27 19:36:24 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {
	// std::cout << "destructor called" << std::endl;
}

RPN::RPN(const RPN& rhs): input_(rhs.input_) {
	
}

RPN::RPN(std::string input): input_(input) {
	
}

const RPN& RPN::operator=(const RPN& rpn) {
	input_ = rpn.input_;
	return *this;
}
void RPN::executeOperation(const std::string::const_iterator& it)
{
	if (intStack_.size() < 2)
		throw std::logic_error("invalid input. Calculation not possible.");
	int first, second;
	double result;
	second = intStack_.top();
	intStack_.pop();
	first = intStack_.top();
	intStack_.pop();
	switch (*it)
	{
	case '+':
		result = first + second;
		break;
	case '-':
		result = first - second;
		break;
	case '*':
		result = first * second;
		break;
	case '/':
		if (second == 0)
			throw std::logic_error("Division by zero. Calculation not possible.");
		result = first / second;
		break;
	default:
		throw std::invalid_argument("invalid operator.");
	}
	if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
		throw std::logic_error("Integer overflow. Calculation not possible.");
	intStack_.push(static_cast<int>(result));
}

void	RPN::solve() {
	while (!intStack_.empty())
		intStack_.pop();
	if (input_.empty())
		throw std::invalid_argument("input cannot be empty.");
	for (std::string::const_iterator it = input_.begin(); it != input_.end(); ++it) {
		if (*it == ' ')
			continue ;
		else if (std::isdigit(*it))
			intStack_.push(*it - '0');
		else
			executeOperation(it);
	}
	if (intStack_.size() != 1)
		throw std::logic_error("invalid input. Calculation not possible.");
	int result = intStack_.top();
	intStack_.pop();
	std::cout << result << std::endl;
}
