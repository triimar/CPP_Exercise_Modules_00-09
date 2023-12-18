/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:52:28 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 21:02:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): size_(0), array_(NULL) {
	std::cout << "default constructor" << std::endl;
};

template <typename T>
Array<T>::~Array() {
	std::cout << "destructor" << std::endl;
	if (this->array_)
		delete[] array_;
	
};

template <typename T>
Array<T>::Array(const unsigned int n): size_(n) {
	std::cout << "constructor" << std::endl;
	if (n)
		array_ = new T[n];
	else
		array_ = NULL;
}

template <typename T>
Array<T>::Array(const Array& rhs): size_(rhs.size_) {
	std::cout << "copy constructor" << std::endl;
	if (rhs.array_)
	{
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = rhs.array_[i];
	}
	else
		array_ = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this != &rhs)
	{
		size_ = rhs.size_;
		if (array_)
			delete[] array_;
		if (rhs.array_)
		{
			array_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++)
				array_[i] = rhs.array_[i];	
		}
		else
			array_ = NULL;	
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int i) const {
	if (i >= 0 && i <= this->size_)
		return array_[i];
	else
		throw IndexOutOfBounds();
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->size_;
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return "Index is out of bounds";
}

template <typename T>
void	Array<T>::printArray() const {
	if (array_ != NULL)
	{
		for (unsigned int i = 0; i < size_; i++)
			std::cout << "|" << array_[i] << "| ";
	}
	std::cout << std::endl;
}