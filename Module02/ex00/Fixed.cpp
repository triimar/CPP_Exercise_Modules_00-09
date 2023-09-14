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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumVal = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumVal;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNumVal = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
