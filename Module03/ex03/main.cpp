/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 20:09:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("Tobu");
	ScavTrap b("Liilu");
	FragTrap c("Stuart");
	std::cout << std::endl;
	
	b.attack("the wall");
	b.takeDamage(7);
	b.beRepaired(3);
	b.attack("the mosquito");
	b.takeDamage(7);
	b.beRepaired(3);
	b.guardGate();
	std::cout << std::endl;

	a.attack("the wall");
	a.takeDamage(7);
	a.beRepaired(3);
	a.attack("the mosquito");
	a.takeDamage(7);
	a.beRepaired(3);
	std::cout << std::endl;

	c.attack("the wall");
	c.takeDamage(7);
	c.beRepaired(3);
	c.attack("the mosquito");
	c.takeDamage(7);
	c.beRepaired(3);
	c.highFiveGuys();
	std::cout << std::endl;
}