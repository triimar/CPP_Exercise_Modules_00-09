/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:56:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/23 15:39:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& rhs):  std::stack<T, Container>(rhs) {	
}

//this calls the = operator in the base class and uses it to copy the content
template <typename T, typename Container>
MutantStack<T, Container>&  MutantStack<T, Container>::operator=(const MutantStack& rhs) {
	if (this != &rhs)
		std::stack<T, Container>::operator=(rhs);
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin() const {
	return this->c.cbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend() const {
	return this->c.cend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
	return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const {
	return this->c.rend();
}

#endif