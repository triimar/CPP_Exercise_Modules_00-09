/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:53:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 15:03:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& rhs);
	WrongCat& operator=(const WrongCat& rhs);
	
	void	makeSound() const;
};

#endif