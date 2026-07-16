/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:46:28 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:46:29 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <stack>

// Affiche le contenu d'un MutantStack via ses iterateurs (bas -> haut de la pile).
template <typename T, typename Container>
static void printMutantStack(MutantStack<T, Container>& mstack)
{
	typename MutantStack<T, Container>::iterator it = mstack.begin();
	typename MutantStack<T, Container>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

// Meme affichage avec une std::list pour comparer l'ordre d'iteration (comme le sujet le suggere).
static void printList(std::list<int>& lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
}

// Programme de test pour l'exercice 02 (Mutated abomination).
// Chaque section illustre un point du sujet en lançant ./mutantstack.

int main()
{
	// === Test 1 : exemple officiel du sujet ===
	// Sujet : push/top/pop/size, iterateurs (++/--), copie vers std::stack.
	// Attendu : top=17, size=1 apres pop, puis iteration sur les elements restants.
	std::cout << "=== Test 1 : exemple officiel du sujet ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << "Copie std::stack size : " << s.size() << std::endl;
	}

	// === Test 2 : pile vide (begin == end) ===
	// Cas limite : une pile vide n'a aucun element a parcourir.
	std::cout << "\n=== Test 2 : pile vide ===" << std::endl;
	{
		MutantStack<int> mstack;

		if (mstack.begin() == mstack.end())
			std::cout << "begin() == end() sur pile vide : OK" << std::endl;
		else
			std::cout << "ERREUR : iterateurs differents sur pile vide" << std::endl;

		std::cout << "size : " << mstack.size() << std::endl;
	}

	// === Test 3 : un seul element ===
	std::cout << "\n=== Test 3 : un seul element ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(42);

		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "via iterateur : " << *mstack.begin() << std::endl;
	}

	// === Test 4 : ordre d'iteration (bas -> haut) ===
	// Le parcours doit suivre l'ordre du conteneur sous-jacent (deque par defaut).
	std::cout << "\n=== Test 4 : ordre d'iteration bas vers haut ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "Attendu : 1 2 3 (du bas vers le haut)" << std::endl;
		printMutantStack(mstack);
	}

	// === Test 5 : iterateurs const ===
	std::cout << "\n=== Test 5 : iterateurs const ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		const MutantStack<int>& ref = mstack;
		MutantStack<int>::const_iterator it = ref.begin();
		MutantStack<int>::const_iterator ite = ref.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	// === Test 6 : iterateurs reverse (haut -> bas) ===
	std::cout << "\n=== Test 6 : iterateurs reverse ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "Attendu : 3 2 1 (du haut vers le bas)" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}

	// === Test 7 : OCF (constructeur de copie + affectation) ===
	std::cout << "\n=== Test 7 : constructeur de copie et affectation ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(7);
		original.push(8);
		original.push(9);

		MutantStack<int> copied(original);
		MutantStack<int> assigned;
		assigned = original;

		std::cout << "original size : " << original.size() << std::endl;
		std::cout << "copie size : " << copied.size() << std::endl;
		std::cout << "affecte size : " << assigned.size() << std::endl;

		std::cout << "copie top : " << copied.top() << std::endl;
		std::cout << "affecte top : " << assigned.top() << std::endl;
	}

	// === Test 8 : modification via iterateur ===
	// Verifie que l'iterateur pointe bien vers le conteneur interne modifiable.
	std::cout << "\n=== Test 8 : modification via iterateur ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(100);
		mstack.push(200);

		*mstack.begin() = 111;
		std::cout << "Premier element modifie : " << *mstack.begin() << std::endl;
		std::cout << "top inchange : " << mstack.top() << std::endl;
	}

	// === Test 9 : comparaison MutantStack vs std::list (sujet) ===
	// Le sujet dit que remplacer MutantStack par std::list donne la meme sortie.
	std::cout << "\n=== Test 9 : meme ordre que std::list ===" << std::endl;
	{
		std::cout << "--- MutantStack ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		printMutantStack(mstack);

		std::cout << "--- std::list (memes operations) ---" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.pop_back();
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		printList(lst);
	}

	// === Test 10 : MutantStack avec std::list comme conteneur sous-jacent ===
	std::cout << "\n=== Test 10 : MutantStack base sur std::list ===" << std::endl;
	{
		MutantStack<int, std::list<int> > mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "size : " << mstack.size() << std::endl;
		std::cout << "top : " << mstack.top() << std::endl;
		printMutantStack(mstack);
	}

	return (0);
}
