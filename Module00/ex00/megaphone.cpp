/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:30:23 by tmarts            #+#    #+#             */
/*   Updated: 2023/08/21 15:57:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int count = 1; count < argc; ++count)
	{
		for (char *c = argv[count]; *c != '\0'; ++c)
			std::cout << static_cast<char>(std::toupper(*c));
	}
	std::cout << std::endl;
	return 0;
}

//cout is the name of the standard output stream in C++
//the insertion operator (<<) indicates that what follows is inserted into std::cout.

// Just to make sure that everybody is awake, write a program that behaves as follows:
       
// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF. $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *
// $>