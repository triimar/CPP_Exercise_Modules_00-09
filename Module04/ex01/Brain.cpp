/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:26:53 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 19:04:08 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &rhs) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = rhs;
}

Brain &Brain::operator=(const Brain &rhs) {
    std::cout << "Brain copy assignment operator called" << std::endl;
	if ( this != &rhs) {
   		for (int i = 0; i < 100; i++) {
        	this->ideas[i] = rhs.ideas[i];
    	}
	}
    return (*this);
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
}

