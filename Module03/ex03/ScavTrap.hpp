/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:31:46 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/14 21:57:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

# include<iostream>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap 
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & rhs);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	attack(const std::string &target);	
	void	guardGate();
};

#endif