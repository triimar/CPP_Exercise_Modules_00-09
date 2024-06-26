/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:09:18 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/12 19:57:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>

class Fixed
{
private:
	int 				_fixedPointNumVal;
	static int const	_fractionalBits;

public:
	Fixed(); //								default constructor
	Fixed(const Fixed & rhs); //			copy constructor
	Fixed & operator=(const Fixed & rhs); //assignment operator
	~Fixed(); //							destructor

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif