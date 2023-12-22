/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:50:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/23 00:06:17 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <set>
#include <limits>
#include <ctime> //for std::time
#include <cstdlib> //for std::rand()

class Span {

private:
	unsigned int		maxSize_;
	std::multiset<int>	storage_;
	Span();

public:
	Span(unsigned int N);
	~Span();
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	
	void addNumber(int n);
	
	template <typename T>
	void addNumbers(T first, T last);
	
	int	shortestSpan() const;
	int longestSpan() const;
	
	std::multiset<int>	getStoredInts() const;
	unsigned int		getMaxSize() const;
	
	class NoSpanPossibleException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class SpanIsFullException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

template <typename T>
void Span::addNumbers(T first, T last) {
	if (this->storage_.size() == this->maxSize_)
		throw	SpanIsFullException() ;
	else if (this->storage_.size() + std::distance(first, last) > this->maxSize_) {
		while (first != last)
		{
			addNumber(*first);
			++first;
		}
	}
	else
		this->storage_.insert(first, last);
}

std::ostream& operator<<(std::ostream& o, const Span& s);


template <typename Cont>
Cont getFilledIntContainer(unsigned int size)
{
	Cont result;
	std::srand(std::time(0));
	for (unsigned int i = 0; i < size; i++) {
		int rand_val = std::rand() % 200001;
		result.push_back(rand_val);
	}
	return(result);
}

#endif