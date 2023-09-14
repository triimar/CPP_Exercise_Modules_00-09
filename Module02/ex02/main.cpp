/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:21:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/13 16:27:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	
	
	std::cout << std::endl << "=== Comparisons ===" << std::endl;
	std::cout << "a > b? : " << (a > b) << std::endl;
	std::cout << "a <= b? : " << (a <= b) << std::endl;

	std::cout << std::endl << "=== Aritmetic operators ===" << std::endl;
	Fixed x(2.5f);
	Fixed y(3);
	std::cout << "x + y : " << (x + y) << std::endl;
	std::cout << "x - y : " << (x - y) << std::endl;
	std::cout << "x * y? : " << (x * y) << std::endl;
	std::cout << "x / y? : " << (x / y) << std::endl;
	
    std::cout << std::endl << "=== Incremet-dectement ===" << std::endl;
	Fixed c(1);
    std::cout << "c: " << c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "++c: " << ++c << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "c++: " << c++ << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "--c: " << --c << std::endl;
    std::cout << "c: " << c << std::endl << std::endl;
	return 0;
}
