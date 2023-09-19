/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:57:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 22:21:39 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();
	~Cure();
	Cure(const Cure& rhs);
	Cure&	operator=(const Cure& rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
};


#endif
