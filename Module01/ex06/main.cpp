/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:33:53 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/09 16:59:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	
	Harl Hhhh;
	if (argc != 2) {
		std::cout << "specify one complaint level (DEBUG, INFO, WARNING or ERROR)" << std::endl;
		return 1;
	}
	std::string level = argv[1];
	Hhhh.complain(level);
	return 0;
}