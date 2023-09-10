/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:12:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/09 18:17:06 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	HumanB jim("Jim");
	std::cout << std::endl;
	
	std::cout << "-------just after instantiating------" << std::endl;
	bob.attack();
	jim.attack();
	std::cout << std::endl;
	
	std::cout << "-------setting the weapon for HumanB------" << std::endl;
	jim.setWeapon(club);
	bob.attack();
	jim.attack();
	std::cout << std::endl;
	
	std::cout << "------------resetting the weapon----------" << std::endl;
	club.setType("toothpick"); 
	bob.attack();
	jim.attack();
	std::cout << std::endl;
	
	// system("leaks violence");
	return 0;
} 

