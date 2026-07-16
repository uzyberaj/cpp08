/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:38 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:39 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementation du template MutantStack.
// std::stack expose le conteneur interne via le membre protege "c" (deque par defaut).
// Les iterateurs parcourent le conteneur du bas vers le haut de la pile.

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
	: std::stack<T, Container>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}
