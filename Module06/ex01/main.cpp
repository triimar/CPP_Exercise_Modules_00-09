/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:08:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/15 19:03:44 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"


int	main(void)
{
	Data data_one;
	data_one.name = "Bella";
	data_one.d = 6;
	
	Data *two = new Data;
	two->name = "Hugo";
	two->d = 9;

	uintptr_t one_raw = Serializer::serialize(&data_one);
	uintptr_t two_raw = Serializer::serialize(two);
	
	Data *one_deserialized = Serializer::deserialize(one_raw);
	Data *two_deserialized = Serializer::deserialize(two_raw);

	std::cout << one_deserialized->name << " " << one_deserialized->d << std::endl;
	
	if (two == two_deserialized)
		std::cout << two_deserialized->name << " " << two_deserialized->d << std::endl;
	else
		std::cout << "FAILURE!" << std::endl;
	
	delete two;
}

