/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:45:57 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:45:58 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementation du template easyfind (fichier .tpp inclus par easyfind.hpp).
// std::find parcourt le conteneur avec des iterateurs et renvoie un iterateur
// sur la premiere occurrence, ou end() si rien n'est trouve.

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator result = std::find(container.begin(), container.end(), value);

	if (result == container.end())
		throw NotFoundException();
	return (result);
}
