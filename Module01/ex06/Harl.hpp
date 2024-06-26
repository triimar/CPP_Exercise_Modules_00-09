/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:51:34 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/06 18:35:46 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include<iostream>
#include<string>

class	Harl {
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();
	void    complain(std::string level);
};

#endif

