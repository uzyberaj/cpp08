/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:45:43 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:45:44 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iterator>

// Exception lancee quand easyfind ne trouve pas la valeur cherchee.
// Le sujet laisse le choix : exception ou valeur d'erreur ; on choisit une exception.
class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw();
};

// Fonction template easyfind : cherche la premiere occurrence d'un int dans un conteneur d'entiers.
// T doit etre un conteneur STL sequentiel (vector, list, deque...) avec begin() / end().
// On utilise std::find (algorithme STL) au lieu d'une boucle manuelle.
template <typename T>
typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"

#endif
