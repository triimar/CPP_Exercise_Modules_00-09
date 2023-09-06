/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:33:53 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/06 18:41:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	
	Harl Hhhh;
	
	std::cout << std::endl;
	Hhhh.complain("DEBUG");
	std::cout << std::endl;
	Hhhh.complain("INFO");
	std::cout << std::endl;
	Hhhh.complain("WARNING");
	std::cout << std::endl;
	Hhhh.complain("ERROR");
	std::cout << std::endl;
	Hhhh.complain("none");
}