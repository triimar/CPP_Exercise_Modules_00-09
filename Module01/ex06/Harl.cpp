/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:51:25 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/09 17:43:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {
	
}
	
void Harl::debug() {
	
	std::cout << "[ DEBUG ] " 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" 
	<< std::endl;
}

void Harl::info() {
	
	std::cout << "[ INFO ] "
	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void Harl::warning() {
	
	std::cout << "[ WARNING ] "
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ] "
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level) {
	
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int lev = 0;
	for (int i = 0; i < 4; ++i) {
    	if (levels[i] == level) {
			lev = i + 1;
			break ;
		}	
	}
	switch (lev) {
		case 1:
			(this->*complaints[0])();
		case 2:
			(this->*complaints[1])();
		case 3:
			(this->*complaints[2])();
		case 4:
			(this->*complaints[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
