/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:38:06 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 20:05:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string		_name;
	AMateria		*_inventory[4];
	int				_invSlot;
	AMateria		*_unequippedI[4];
	int				_trashNr;		
	
	Character();
public:
	Character(std::string name);
	~Character();
	Character(const Character& rhs);
	Character& operator=(const Character& rhs);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif
