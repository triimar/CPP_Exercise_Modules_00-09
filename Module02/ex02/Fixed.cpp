/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:07:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/13 15:34:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointNumVal(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const N) {
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointNumVal = N * (1 << _fractionalBits);
}

Fixed::Fixed(float const N) {
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointNumVal = static_cast<int>(roundf(N * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & rhs) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumVal = rhs.getRawBits();
	return *this;	
}

bool	Fixed::operator>(const Fixed & rhs) {
	if (this->_fixedPointNumVal > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed & rhs) {
	if (this->_fixedPointNumVal < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed & rhs) {
	if (this->_fixedPointNumVal >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed & rhs) {
	if (this->_fixedPointNumVal <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed & rhs) {
	if (this->_fixedPointNumVal == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed & rhs) {
		if (this->_fixedPointNumVal != rhs.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed & rhs) {
	Fixed	result;
	result.setRawBits(this->_fixedPointNumVal + rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed & rhs) {
	Fixed	result;
	result.setRawBits(this->_fixedPointNumVal - rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed & rhs) {
	Fixed	result;
	int	multiply = (this->_fixedPointNumVal * rhs.getRawBits()) >> _fractionalBits;
	result.setRawBits(multiply);
	return result ;
}

Fixed	Fixed::operator/(const Fixed & rhs) {
	Fixed	result;
	int scaledNumerator = this->_fixedPointNumVal << _fractionalBits;
	int divide = scaledNumerator / rhs.getRawBits();
	result.setRawBits(divide);
	return result;
}

Fixed &	Fixed::operator++() {
	this->_fixedPointNumVal++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	++*this;
	return temp;
}

Fixed &	Fixed::operator--() {
	this->_fixedPointNumVal--;
	return *this;	
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	--*this;
	return temp;
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

Fixed & Fixed::min(Fixed & one, Fixed & two) {
	if (one <= two)
		return (one);
	return (two);
}

const Fixed & Fixed::min(const Fixed & one, const Fixed & two) {
	if (one.getRawBits() <= two.getRawBits())
		return (one);
	return (two);
}

Fixed & Fixed::max(Fixed & one, Fixed & two) {
	if (one >= two)
		return (one);
	return (two);
}

const Fixed & Fixed::max(const Fixed & one, const Fixed & two) {
	if (one.getRawBits() >= two.getRawBits())
		return (one);
	return (two);
}

std::ostream & operator<<(std::ostream & out, const Fixed & rhs) {
	
	out << rhs.toFloat();
	return out;	// returning allows to chain several instances
}