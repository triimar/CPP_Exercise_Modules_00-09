/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:34:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/17 21:14:50 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
# include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal& rhs);
	AAnimal& operator=(const AAnimal& rhs);
	
	std::string	getType() const;
	virtual void	makeSound() const = 0;
};


#endif