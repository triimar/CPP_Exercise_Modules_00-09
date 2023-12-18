/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:58:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/18 20:56:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class	Array {
private:
	unsigned int 	size_;
	T				*array_;
public:
	Array();
	Array(const unsigned int n);
	~Array();
	Array(const Array& rhs);

	Array& operator=(const Array& rhs);

	T&	operator[](const unsigned int n) const;
	unsigned int size() const;
	void	printArray() const;
	
	class IndexOutOfBounds : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif