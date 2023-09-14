/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:08:55 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/13 15:55:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

Fixed a; // default constructor called
Fixed b(a); // copy constructor called
Fixed c;
c = b; // copy assignment operator called
//we use default constructor that initializes the fixed-point number value to 0.
std::cout << a.getRawBits() << std::endl; 
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
//setting new fixed point number (raw) values:
a.setRawBits(1);
b.setRawBits(12);
c.setRawBits(123);
//displaying the new fixed-point number values:
std::cout << a.getRawBits() << std::endl; 
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
