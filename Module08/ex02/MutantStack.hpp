/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:55:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/12/22 23:43:05 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include<deque>
# include<stack>


template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container> {

public:
	MutantStack();
	MutantStack(const MutantStack& rhs);
	MutantStack &operator=(const MutantStack& rhs);
	virtual ~MutantStack();	
	
	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;
	
	iterator begin();
	iterator end();
	const_iterator	cbegin() const;
	const_iterator	cend() const;	
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
	
};

/*
instead of using typedef it is possible to use only:

	typename std::stack<T, Container>::container_type::iterator begin();
	typename std::stack<T, Container>::container_type::iterator end();

but not creating the alias "iterator" in the class makes the code longer and 
declaration of the variable outside the class more inconvenient and less readable
In main it would be then:

	std::stack<int, std::deque<int>>::container_type::iterator it = mstack.begin();
	std::stack<int, std::deque<int>>::container_type::iterator it_e= mstack.end();
*/
#include "MutantStack.tpp"

#endif