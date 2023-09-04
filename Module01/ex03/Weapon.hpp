/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:35:25 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/04 17:58:11 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();
	
	void 				setType(std::string newType);
	std::string const	& getType();
};

#endif