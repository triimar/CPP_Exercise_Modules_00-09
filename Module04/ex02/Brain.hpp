/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:27:05 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 18:45:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain {
public:
	std::string ideas[100];

	Brain();
	~Brain();
	Brain(const Brain& rhs);
	Brain& operator=(const Brain& rhs);

	void			setIdea(int i, std::string idea);
	std::string 	getIdea(int i) const;
};

#endif