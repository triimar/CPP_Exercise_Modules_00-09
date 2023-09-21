/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:54:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/21 20:10:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main() {
	ICharacter* bob = new Character("Bob");
	ICharacter* me = new Character("Mary");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	src->learnMateria(NULL);						//to test if Materia pointer is not given
	
	src->learnMateria(new Ice());				//to test if MateriaSource slots get full
	src->learnMateria(new Cure());
	AMateria* leftover = new Cure();
	src->learnMateria(leftover);				
	delete leftover;		
	me->use(0, *bob);							//to test errors of the use and unequip functions
	me->unequip(2);
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("lill");			//to try to find Materia that does not exit
	
	tmp = src->createMateria("ice");				// Equpping & unequipping extra test
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	me->unequip(2);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(1);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(0);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(3);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(3); 
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	system("leaks amateria");
	return 0;
}
