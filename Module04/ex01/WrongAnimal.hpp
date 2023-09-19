/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:53:54 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:00:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	WrongAnimal& operator=(const WrongAnimal &rhs);
	
	std::string	getType() const;
	void	makeSound() const;
};


#endif