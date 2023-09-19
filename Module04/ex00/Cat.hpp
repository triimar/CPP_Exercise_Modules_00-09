/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 17:08:03 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal {
	
public:
	Cat();
	~Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	
	virtual void	makeSound() const;
};

#endif