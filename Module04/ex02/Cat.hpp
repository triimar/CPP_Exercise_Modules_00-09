/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 21:18:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {

private:
	Brain	*_brain;

public:
	Cat();
	~Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	
	virtual void			makeSound() const;
	void					setIdea(int i, std::string idea);
	std::string 			getIdea(int i) const;
};

#endif