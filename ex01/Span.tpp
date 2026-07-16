/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:21 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:22 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iterator>

// Template addRange : ajoute une sequence d'entiers sans appeler addNumber() en boucle manuelle.
// On verifie d'abord qu'on ne depasse pas la capacite N, puis on utilise insert() du vector.

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	std::size_t toAdd = static_cast<std::size_t>(std::distance(begin, end));

	if (_numbers.size() + toAdd > _maxSize)
		throw SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
}
