/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:07:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/12 19:57:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointNumVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const N) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNumVal = N * (1 << _fractionalBits);
}

Fixed::Fixed(float const N) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNumVal = static_cast<int>(roundf(N * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumVal = rhs.getRawBits();
	return *this;	
}

int		Fixed::getRawBits() const {
	return this->_fixedPointNumVal;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNumVal = raw;
}

int Fixed::toInt() const {
	int intVal;
	
	intVal = this->getRawBits() >> _fractionalBits;
	return intVal;
}

float	Fixed::toFloat() const {
	float	floatVal;

	floatVal = static_cast<float>(this->getRawBits()) / static_cast<float>(1 << _fractionalBits);
	return floatVal;
}

std::ostream & operator<<(std::ostream & out, const Fixed & rhs) {
	
	out << rhs.toFloat();
	return out;	
}