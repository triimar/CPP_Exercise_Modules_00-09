/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:50:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/21 22:58:14 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span {

private:
	unsigned int		maxSize_;
	std::vector<int>	*storage_;
	Span();

public:
	Span(unsigned int N);
	~Span();
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	
	void addNumber(int n);
	
	// template <typename inputIt>
	// void addNumbers(inputIt first, inputIt last);
	
	int	shortestSpan() const;
	int longestSpan() const;
	
	std::vector<int> getStoredInts() const;
	
	class NoSpanPossible : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class SpanIsFull : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& o, const Span& s);

#endif