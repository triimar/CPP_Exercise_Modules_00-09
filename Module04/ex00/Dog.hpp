/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 17:07:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal {
	
public:
	Dog();
	~Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);

	virtual void makeSound() const;
};

#endif