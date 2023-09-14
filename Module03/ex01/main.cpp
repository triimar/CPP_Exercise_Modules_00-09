/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 21:26:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap b("Tobu");
	ScavTrap Liilu("Liilu");
	ScavTrap a(Liilu);
	
	std::cout << std::endl;
	a.attack("the wall");
	a.takeDamage(7);
	a.beRepaired(3);
	a.attack("the mosquito");
	a.takeDamage(7);
	a.beRepaired(3);
	a.guardGate();
	std::cout << std::endl;
		
	b.attack("the wall");
	b.takeDamage(7);
	b.beRepaired(3);
	b.attack("the mosquito");
	b.takeDamage(7);
	b.beRepaired(3);
	std::cout << std::endl;
}