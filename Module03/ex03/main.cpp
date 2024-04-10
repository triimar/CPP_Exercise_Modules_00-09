/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:52 by tmarts            #+#    #+#             */
/*   Updated: 2024/04/04 14:59:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap b("Liilu");
	std::cout << std::endl;
	b.whoAmI();
	std::cout << std::endl;
	b.attack("the wall");
	b.takeDamage(7);
	b.beRepaired(3);
	b.attack("the mosquito");
	b.takeDamage(7);
	b.beRepaired(3);
	std::cout << std::endl;
	b.guardGate();
	b.highFiveGuys();
	std::cout << std::endl;
}