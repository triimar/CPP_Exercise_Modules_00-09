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
#include<cmath>


class Fixed
{
private:
	int 				_fixedPointNumVal;
	static int const	_fractionalBits;
	
public:
	Fixed();
	Fixed(int const N);
	Fixed(float const N);
	Fixed(const Fixed & rhs);
	Fixed & operator=(const Fixed & rhs);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
	
};

std::ostream & operator<<(std::ostream & out, const Fixed & rhs);

#endif