/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 17:36:31 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {

	Zombie	*horde = zombieHorde(5, "Ugggggghh");
	for (int i = 0; i < 5; ++i) {
		std::cout << "Zombie index" << i << std::endl;
		horde[i].announce();
	}
	
	std::cout << std::endl << "SETTING SOME NEW NAMES" << std::endl;
	horde[0].setName("Prima");
	horde[2].setName("Unique Flower");
	for (int i = 0; i < 5; ++i) {
		std::cout << "Zombie index " << i << std::endl;
		horde[i].announce();
	}
	
	std::cout << std::endl;
	delete[] horde;
	
	std::cout << std::endl << "CREATING A HORDE OF ONE" << std::endl;
	std::cout << std::endl;
	Zombie *soloHorde = zombieHorde(1, "Lonely Lulu");
	soloHorde->announce();

	std::cout << std::endl;
	delete[] soloHorde;
	// system("leaks moar_brainzzz");
	return 0;
}