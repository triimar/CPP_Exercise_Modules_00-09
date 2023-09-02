/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/02 16:35:56 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {

	Zombie	*oneUndead = newZombie("Ursula");
	oneUndead->announce();
	
	randomChump("John Doe");
	delete oneUndead;
	return 0;
}