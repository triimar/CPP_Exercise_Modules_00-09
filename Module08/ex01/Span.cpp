/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:49:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/23 00:01:46 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize_(0), storage_(std::multiset<int>()) {
	
}

Span::Span(unsigned int N) : maxSize_(N), storage_(std::multiset<int>()) {
	
}

Span::~Span() {
}
	
Span::Span(const Span& rhs) \
		: maxSize_(rhs.maxSize_), storage_(std::multiset<int>(rhs.storage_)) {
	
}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs)
	{
		this->maxSize_ = rhs.maxSize_;
		storage_ = std::multiset<int>(rhs.storage_);
	}
	return (*this);
}
	
void Span::addNumber(int n) {
	if (storage_.size() < maxSize_)
		storage_.insert(n);
	else
		throw SpanIsFullException();
}

int Span::shortestSpan() const{
	if (storage_.size() <= 1)
		throw NoSpanPossibleException();
	int shortest = std::numeric_limits<int>::max();
	std::multiset<int>::iterator it = storage_.begin();
	std::multiset<int>::iterator next = it;
	++next;
	while (next != storage_.end()) {
		shortest = std::min((*next - *it), shortest);
		if (shortest == 0)
			break ;
		++it;
		++next;
	}
	return (shortest);
}

int Span::longestSpan() const {
	
	if (storage_.size() <= 1)
		throw NoSpanPossibleException();
	int longest = *(--storage_.end()) - *(storage_.begin());
	return (longest);
}

std::multiset<int> Span::getStoredInts() const {
	return storage_;
}
unsigned int	Span::getMaxSize() const {
	return maxSize_;
}

const char* Span::NoSpanPossibleException::what() const throw() {
	return ("Not enough elements to calculate span");
}

const char*  Span::SpanIsFullException::what() const throw() {
	return ("Storage for integers is full");
}

std::ostream& operator<<(std::ostream& o, const Span& s) {
	std::multiset<int> temp = s.getStoredInts();
	for (std::multiset<int>::iterator it = temp.begin(); it != temp.end(); ++it)
        std::cout << *it << " ";
	return o;
}
