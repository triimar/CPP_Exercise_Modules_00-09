/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:47:59 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/19 16:55:59 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
private:
	AMateria(); //defaut constructor should not be used
protected:
	std::string	_type;
	
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria& rhs);
	AMateria& operator=(const AMateria& rhs);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif