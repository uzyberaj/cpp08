/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:45:38 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:45:39 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Implementation de what() pour l'exception (pas dans le .tpp car ce n'est pas un template).
const char* NotFoundException::what() const throw()
{
	return "Element not found";
}
