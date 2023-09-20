/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:56:35 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/20 18:06:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _slotsFilled(0) {
	std::cout << "\033[90mCONSTRUCTOR: MateriaSource\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		this->_learnedMateria[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "\033[90mDESTRUCTOR: MateriaSource\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->_learnedMateria[i])
			delete _learnedMateria[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& rhs): _slotsFilled(rhs._slotsFilled) {
	std::cout << "\033[90mCOPY CONSTRUCTOR: MateriaSource\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (rhs._learnedMateria[i])
			this->_learnedMateria[i] = rhs._learnedMateria[i]->clone();
		else
			this->_learnedMateria[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	std::cout << "\033[90mCOPY ASSIGNMENT OPERATOR: MateriaSource\033[0m"<< std::endl;
	if (this != &rhs) {
		this->_slotsFilled = rhs._slotsFilled;
		for (size_t i = 0; i < 4; i++) {
			if (this->_learnedMateria[i])
				delete this->_learnedMateria[i];
			if (rhs._learnedMateria[i])
				this->_learnedMateria[i] = rhs._learnedMateria[i]->clone();
			else
				this->_learnedMateria[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "ERROR no Materia given for learning" << std::endl;
		return ;
	}
	if (_slotsFilled == 4) {
		std::cout << "ERROR MateriaSource is full. No more learning possible" << std::endl;
		return ;
	}
		_learnedMateria[_slotsFilled] = m;
		_slotsFilled++;
		std::cout << "MateriaSource: Materia " << m->getType() << " learned" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < _slotsFilled; i++) {
		if (_learnedMateria[i]->getType() == type) {
			std::cout << "MateriaSource: Materia " << type << " created" << std::endl;
			return _learnedMateria[i]->clone();
		}
	}
	std::cout << "ERROR Materia " << type << " not found in MateriaSource" << std::endl;
	return NULL;
}