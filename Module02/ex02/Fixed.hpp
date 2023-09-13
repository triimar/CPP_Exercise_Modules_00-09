/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:09:18 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/13 15:42:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>
#include<cmath>

class Fixed
{
private:
	int 				_fixedPointNumVal;
	static int const	_fractionalBits;
	
public:
	Fixed();				//canonical // constructor
	Fixed(int const N);
	Fixed(float const N);
	
	Fixed(const Fixed & a); //canonical // copy constructor
	Fixed & operator=(const Fixed & rhs); // canonical // assignment operator
	~Fixed(); //canonical // destructor
	
	bool	operator>(const Fixed & rhs); 
	bool	operator<(const Fixed & rhs);
	bool	operator>=(const Fixed & rhs);
	bool	operator<=(const Fixed & rhs);
	bool	operator==(const Fixed & rhs);
	bool	operator!=(const Fixed & rhs);
	Fixed	operator+(const Fixed & rhs);
	Fixed	operator-(const Fixed & rhs);
	Fixed	operator*(const Fixed & rhs);
	Fixed	operator/(const Fixed & rhs);
	Fixed &	operator++();
	Fixed	operator++(int);
	Fixed &	operator--();
	Fixed	operator--(int);
	
	static Fixed & min(Fixed & one, Fixed & two);
	static const Fixed & min(const Fixed & one, const Fixed & two);
	static Fixed & max(Fixed & one, Fixed & two);
	static const Fixed & max(const Fixed & one, const Fixed & two);
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
	
};

std::ostream& operator<<(std::ostream& outputStr, const Fixed& a); //just overloading a function

#endif