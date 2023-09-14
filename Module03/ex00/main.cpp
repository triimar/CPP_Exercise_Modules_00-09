/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:39:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 21:26:02 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Jupi");
	// ClapTrap Mai(a);
	// ClapTrap Nameless;
	// ClapTrap Nameless = a;
	
	a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	// a.attack("the mosquito");
	a.takeDamage(7);
	a.beRepaired(3);
	a.attack("the mosquito");
	a.takeDamage(7);
	a.beRepaired(3);
	
}