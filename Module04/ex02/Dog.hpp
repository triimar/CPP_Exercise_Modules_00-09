/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 21:17:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal {

private:
	Brain	*_brain;

public:
	Dog();
	~Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);

	virtual void 	makeSound() const;
	void			setIdea(int i, std::string idea);
	std::string 	getIdea(int i) const;
};

#endif