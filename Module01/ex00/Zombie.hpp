/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:28 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/02 16:03:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie {

private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie();

	void		announce();
	
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif
