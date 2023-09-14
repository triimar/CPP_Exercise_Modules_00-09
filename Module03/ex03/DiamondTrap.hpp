/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:35:48 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 21:58:46 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
	
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap & rhs);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	~DiamondTrap();
	
	using ScavTrap::attack;
	// Hit points (FragTrap)
	// Energy points (ScavTrap)
	// Attack damage (FragTrap)
	
	void whoAmI();
};

#endif