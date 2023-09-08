/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:09:18 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/08 15:24:13 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>

class Fixed
{
private:
	int _numValue;
	static int const	_fractBits;
	
public:
	Fixed();
	Fixed(const Fixed &a); //copy constructor
	Fixed &operator=(const Fixed &a); //assignment operator
	~Fixed();

	int		getRawBits() const;
	void	set_RawBits(int const raw);
};

#endif