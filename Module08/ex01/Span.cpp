/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:49:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/21 22:59:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize_(0), storage_(new std::vector<int>()) {
	
}

Span::Span(unsigned int N) : maxSize_(N), storage_(new std::vector<int>()) {
	
}

Span::~Span() {
	delete storage_;
}
	
Span::Span(const Span& rhs) \
		: maxSize_(rhs.maxSize_), storage_(new std::vector<int>(*rhs.storage_)) {
	
}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs)
	{
		delete this->storage_;
		this->maxSize_ = rhs.maxSize_;
		storage_ = new std::vector<int>(*rhs.storage_);
	}
	return (*this);
}
	
void Span::addNumber(int n) {
	if (storage_->size() < maxSize_)
		storage_->push_back(n);
	else
		throw SpanIsFull();
}

int Span::shortestSpan() {
	
}

int Span::longestSpan() {
	
}

std::vector<int> Span::getStoredInts() const {
	return *storage_;
}

const char* Span::NoSpanPossible::what() const throw() {
	return ("Not enough elements to calculate span");
}

const char*  Span::SpanIsFull::what() const throw() {
	return ("Storage for integers is full");
}

std::ostream& operator<<(std::ostream& o, const Span& s) {
	std::vector<int> temp = s.getStoredInts();
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
        std::cout << *it << " ";
	return o;
}