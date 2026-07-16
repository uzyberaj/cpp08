/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:15 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:16 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <numeric>

// --- OCF ---

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

// --- Membres ---

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	// Copie triee : l'ecart minimal est toujours entre deux voisins dans l'ordre croissant.
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	// adjacent_difference calcule les ecarts entre elements consecutifs.
	std::vector<int> gaps(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), gaps.begin());

	// gaps[0] vaut sorted[0] (pas un ecart) : on cherche le min a partir de gaps[1].
	return (*std::min_element(gaps.begin() + 1, gaps.end()));
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	// minmax_element trouve le min et le max en un seul parcours (algorithme STL).
	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax;
	minmax = std::minmax_element(_numbers.begin(), _numbers.end());

	return (*minmax.second - *minmax.first);
}

// --- Exceptions ---

const char* Span::SpanFullException::what() const throw()
{
	return "Span is already full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to compute a span";
}
