/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:38:28 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 13:39:13 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie {

private:
	std::string _name;

public:
	Zombie();
	~Zombie();

	void		setName(std::string name);
	void		announce();
	
};

Zombie*    zombieHorde(int N, std::string name);

#endif
