/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:09 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:10 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Programme de test pour l'exercice 01 (Span).
// Chaque section illustre un point du sujet en lançant ./span.

int main()
{
	// === Test 1 : exemple officiel du sujet ===
	// Sujet : Span(5), ajout de 6, 3, 17, 9, 11 -> shortestSpan=2, longestSpan=14.
	// Attendu : affiche 2 puis 14.
	std::cout << "=== Test 1 : exemple officiel du sujet ===" << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 2 : Span plein (addNumber) ===
	// Sujet : ajouter un element quand il y a deja N elements -> exception.
	// Attendu : "Span is already full".
	std::cout << "\n=== Test 2 : ajout quand le Span est plein ===" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 3 : shortestSpan avec 0 nombre ===
	// Sujet : moins de 2 nombres -> pas de span possible, exception.
	std::cout << "\n=== Test 3 : shortestSpan avec 0 nombre ===" << std::endl;
	try
	{
		Span sp(5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 4 : shortestSpan avec 1 seul nombre ===
	std::cout << "\n=== Test 4 : shortestSpan avec 1 seul nombre ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 5 : longestSpan avec 1 seul nombre ===
	std::cout << "\n=== Test 5 : longestSpan avec 1 seul nombre ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 6 : addRange avec iterateurs ===
	// Sujet : remplir le Span via une plage d'iterateurs (pas addNumber en boucle).
	// Attendu : shortest=1 (10 et 11), longest=9 (2 et 11).
	std::cout << "\n=== Test 6 : addRange avec une plage d'iterateurs ===" << std::endl;
	try
	{
		std::vector<int> source;
		source.push_back(5);
		source.push_back(2);
		source.push_back(8);
		source.push_back(11);
		source.push_back(10);

		Span sp(5);
		sp.addRange(source.begin(), source.end());

		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 7 : addRange depasse la capacite ===
	// Sujet : toute tentative d'ajout au-dela de N elements doit lever une exception.
	std::cout << "\n=== Test 7 : addRange trop grand pour la capacite ===" << std::endl;
	try
	{
		std::vector<int> source;
		source.push_back(1);
		source.push_back(2);
		source.push_back(3);

		Span sp(2);
		sp.addRange(source.begin(), source.end());
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 8 : nombres non tries (verification des spans) ===
	// Sujet : shortest/longest doivent considerer TOUTES les paires, pas seulement les 2 plus petits.
	// Donnees : 100, 1, 50 -> shortest=49 (50-1), longest=99 (100-1).
	std::cout << "\n=== Test 8 : spans avec nombres non tries ===" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(100);
		sp.addNumber(1);
		sp.addNumber(50);

		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 9 : doublons ===
	// Cas limite : deux valeurs identiques -> shortestSpan = 0.
	std::cout << "\n=== Test 9 : doublons (shortestSpan = 0) ===" << std::endl;
	try
	{
		Span sp(4);
		sp.addNumber(7);
		sp.addNumber(3);
		sp.addNumber(7);
		sp.addNumber(10);

		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 10 : OCF (constructeur de copie + affectation) ===
	// Le sujet demande l'OCF : la copie doit conserver les memes spans.
	std::cout << "\n=== Test 10 : constructeur de copie et affectation ===" << std::endl;
	try
	{
		Span original(3);
		original.addNumber(4);
		original.addNumber(10);
		original.addNumber(7);

		Span copied(original);
		Span assigned(1);
		assigned = original;

		std::cout << "original shortest : " << original.shortestSpan() << std::endl;
		std::cout << "copie shortest : " << copied.shortestSpan() << std::endl;
		std::cout << "affecte shortest : " << assigned.shortestSpan() << std::endl;
		std::cout << "original longest : " << original.longestSpan() << std::endl;
		std::cout << "copie longest : " << copied.longestSpan() << std::endl;
		std::cout << "affecte longest : " << assigned.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 11 : 10 000 nombres (exigence du sujet) ===
	// Sujet : tester avec au moins 10 000 nombres via addRange.
	// Attendu : pas de crash, longestSpan = 9999 (0 a 9999), shortestSpan = 1.
	std::cout << "\n=== Test 11 : 10 000 nombres avec addRange ===" << std::endl;
	try
	{
		const unsigned int count = 10000;
		std::vector<int> big;
		for (unsigned int i = 0; i < count; ++i)
			big.push_back(static_cast<int>(i));

		Span sp(count);
		sp.addRange(big.begin(), big.end());

		std::cout << "shortestSpan (10000 nombres) : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan (10000 nombres) : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	// === Test 12 : 10 000 nombres aleatoires ===
	// Sujet : "More would be even better" — verification supplementaire a grande echelle.
	std::cout << "\n=== Test 12 : 10 000 nombres aleatoires ===" << std::endl;
	try
	{
		const unsigned int count = 10000;
		std::vector<int> randomNumbers;
		std::srand(static_cast<unsigned int>(std::time(0)));

		for (unsigned int i = 0; i < count; ++i)
			randomNumbers.push_back(std::rand() % 100000);

		Span sp(count);
		sp.addRange(randomNumbers.begin(), randomNumbers.end());

		std::cout << "shortestSpan (aleatoire) : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan (aleatoire) : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR inattendue : " << e.what() << std::endl;
	}

	return (0);
}
