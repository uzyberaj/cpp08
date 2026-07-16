/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:18 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:19 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <cstddef>

// Classe Span : stocke au maximum N entiers et calcule les ecarts min/max entre eux.
// Le sujet demande l'OCF pour toutes les classes non-interface.
class Span
{
public:
	Span();
	Span(unsigned int maxSize);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	// Ajoute plusieurs nombres d'un coup via une plage d'iterateurs (sujet ex01).
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);

	int shortestSpan() const;
	int longestSpan() const;

	// --- Exceptions internes ---
	class SpanFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	unsigned int			_maxSize;
	std::vector<int>		_numbers;
};

# include "Span.tpp"

#endif
