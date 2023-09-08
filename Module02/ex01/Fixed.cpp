/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:07:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/08 17:51:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

int const Fixed::_fractBits = 8;

Fixed::Fixed(): _numValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed &Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	_numValue = a.getRawBits();
	return (*this);	
}

int		Fixed::getRawBits() const {
	
}

void	Fixed::set_RawBits(int const raw) {
	
}