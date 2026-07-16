/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:03 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:04 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

// Programme de test pour l'exercice 00 (Easy find).
// Chaque section illustre un point du sujet en lançant ./easyfind.

int main()
{
	// === Test 1 : recherche reussie dans un vector ===
	// Sujet : trouver la premiere occurrence d'un entier dans un conteneur.
	// Attendu : iterateur sur 42, valeur affichee "42".
	std::cout << "=== Test 1 : recherche reussie dans un vector ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(10);
		numbers.push_back(42);
		numbers.push_back(99);

		std::vector<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Valeur trouvee : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 2 : premiere occurrence (doublons) ===
	// Sujet : easyfind doit renvoyer la PREMIERE occurrence, pas la derniere.
	// Attendu : iterateur sur le premier 7 (index 1), pas le second.
	std::cout << "\n=== Test 2 : premiere occurrence avec doublons ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(3);
		numbers.push_back(7);
		numbers.push_back(7);
		numbers.push_back(7);

		std::vector<int>::iterator it = easyfind(numbers, 7);
		std::cout << "Premiere occurrence de 7 a l'index : "
			<< std::distance(numbers.begin(), it) << std::endl;
		std::cout << "Valeur a cet iterateur : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 3 : valeur absente (exception) ===
	// Sujet : si aucune occurrence, lever une exception catchable via std::exception&.
	// Attendu : message "Element not found".
	std::cout << "\n=== Test 3 : valeur absente dans un vector ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);

		easyfind(numbers, 100);
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 4 : conteneur vide (exception) ===
	// Sujet : cas limite, rien a trouver dans un vector vide.
	// Attendu : NotFoundException, pas de crash.
	std::cout << "\n=== Test 4 : conteneur vide ===" << std::endl;
	try
	{
		std::vector<int> empty;
		easyfind(empty, 0);
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 5 : recherche au debut du conteneur ===
	// Sujet : verifier que la recherche fonctionne sur le premier element.
	// Attendu : index 0, valeur 5.
	std::cout << "\n=== Test 5 : element au debut du vector ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(15);

		std::vector<int>::iterator it = easyfind(numbers, 5);
		std::cout << "Index : " << std::distance(numbers.begin(), it)
			<< ", valeur : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 6 : recherche a la fin du conteneur ===
	// Sujet : verifier que la recherche atteint bien le dernier element.
	// Attendu : index 2, valeur 30.
	std::cout << "\n=== Test 6 : element a la fin du vector ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);

		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Index : " << std::distance(numbers.begin(), it)
			<< ", valeur : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 7 : conteneur std::list ===
	// Sujet : T peut etre n'importe quel conteneur sequentiel d'entiers (pas associatif).
	// Attendu : trouve 17 dans la list.
	std::cout << "\n=== Test 7 : recherche dans une std::list ===" << std::endl;
	try
	{
		std::list<int> numbers;
		numbers.push_back(6);
		numbers.push_back(3);
		numbers.push_back(17);
		numbers.push_back(9);

		std::list<int>::iterator it = easyfind(numbers, 17);
		std::cout << "Valeur trouvee dans la list : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 8 : conteneur std::deque ===
	// Sujet : meme fonction easyfind doit marcher avec d'autres conteneurs STL.
	// Attendu : trouve 11 dans le deque.
	std::cout << "\n=== Test 8 : recherche dans un std::deque ===" << std::endl;
	try
	{
		std::deque<int> numbers;
		numbers.push_back(6);
		numbers.push_back(3);
		numbers.push_back(17);
		numbers.push_back(9);
		numbers.push_back(11);

		std::deque<int>::iterator it = easyfind(numbers, 11);
		std::cout << "Valeur trouvee dans le deque : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 9 : valeur negative ===
	// Sujet : le second parametre est un int (negatif inclus).
	// Attendu : trouve -42 sans erreur.
	std::cout << "\n=== Test 9 : recherche d'un entier negatif ===" << std::endl;
	try
	{
		std::vector<int> numbers;
		numbers.push_back(-42);
		numbers.push_back(0);
		numbers.push_back(42);

		std::vector<int>::iterator it = easyfind(numbers, -42);
		std::cout << "Valeur trouvee : " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	return (0);
}
