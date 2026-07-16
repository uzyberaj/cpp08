<p align="left">
  <a href="#--------cpp08--">🇬🇧 English</a> |
  <a href="#--------cpp08---1">🇫🇷 Français</a>
</p>

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="C++ logo" width="150">
  <br>
  cpp08
  <br>
</h1>

<h4 align="center"><em>C++ Module 08 — Templated containers, iterators, and algorithms.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercises-3-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Subject</a> |
  <a href="#-project-overview">Overview</a> •
  <a href="#-code-architecture-and-organization">Architecture</a> •
  <a href="#-operating">Operating</a> •
  <a href="#%EF%B8%8F-compiling-and-testing">Compiling</a>
</p>

---

## 📌 **Project overview**

**cpp08** is the eighth C++ module of the 42 Common Core. It introduces the **STL** (Standard Template Library): **containers** (`vector`, `list`, `deque`, `stack`…), **iterators**, and **algorithms** (`std::find`, `std::sort`, `std::min_element`…).

Unlike previous modules, using STL containers and algorithms is not only allowed — it is **required** wherever appropriate.

The project is split into **3 independent exercises**. All code complies with **C++98**.

### 1. Exercise 00 — Easy find ✅

A **function template** `easyfind(T& container, int value)` that:

* Searches for the **first occurrence** of `value` in a sequential integer container
* Uses **`std::find`** from `<algorithm>` (manual iterator loops are not acceptable)
* Returns an **iterator** to the found element
* Throws `NotFoundException` (inherits from `std::exception`) if the value is not found
* Works with `std::vector`, `std::list`, `std::deque`, etc. (associative containers are not required)

### 2. Exercise 01 — Span ✅

A **`Span`** class that stores up to **N integers** and computes the shortest and longest distance between any two stored values:

* `Span(unsigned int N)` — capacity fixed at construction
* `addNumber(int)` — adds one number; throws `SpanFullException` when full
* `addRange(begin, end)` — adds a range of iterators in a single call (template in `Span.tpp`)
* `shortestSpan()` — minimum gap between any two numbers (STL algorithms: `sort`, `adjacent_difference`, `min_element`)
* `longestSpan()` — maximum gap (`minmax_element`)
* Throws `NoSpanException` when fewer than 2 numbers are stored
* Full **Orthodox Canonical Form**

### 3. Exercise 02 — Mutated abomination ✅

A **`MutantStack<T, Container>`** class template that:

* **Inherits from** `std::stack<T, Container>` (default underlying container: `std::deque`)
* Offers all `std::stack` member functions (`push`, `pop`, `top`, `size`…)
* Adds **iterators** (`begin`, `end`, `rbegin`, `rend` + `const` versions) by exposing the protected underlying container member `c`
* Can be copied into a `std::stack` via inheritance
* Full **Orthodox Canonical Form**

### Error handling ⚠️

| Exercise | Exception | When |
|----------|-----------|------|
| ex00 | `NotFoundException` | Value not found in container |
| ex01 | `SpanFullException` | Adding beyond capacity N |
| ex01 | `NoSpanException` | `shortestSpan()` / `longestSpan()` with 0 or 1 number |

All exceptions inherit from `std::exception` and are catchable via `catch (std::exception& e)`.

---

## 📂 **Code architecture and organization**

```
cpp08/
├── ex00/   easyfind.hpp + easyfind.tpp + easyfind.cpp — easyfind
├── ex01/   Span.hpp + Span.tpp + Span.cpp — Span
├── ex02/   MutantStack.hpp + MutantStack.tpp — MutantStack<T>
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 Function template — `easyfind` (ex00)

| Function | Description |
|----------|-------------|
| `easyfind(T& container, int value)` | Returns an iterator to the first occurrence of `value`; throws `NotFoundException` if not found |

#### 🔹 Class — `Span` (ex01)

| Method | Description |
|--------|-------------|
| `Span(unsigned int maxSize)` | Creates a Span with maximum capacity N |
| `addNumber(int number)` | Adds a single integer; throws if full |
| `addRange(Iterator begin, Iterator end)` | Adds multiple integers via iterator range |
| `shortestSpan() const` | Returns the smallest distance between any two stored numbers |
| `longestSpan() const` | Returns the largest distance between any two stored numbers |

#### 🔹 Class template — `MutantStack<T, Container>` (ex02)

| Method | Description |
|--------|-------------|
| `push(val)` / `pop()` / `top()` / `size()` / `empty()` | Inherited from `std::stack` |
| `begin()` / `end()` | Iterators over the underlying container (bottom → top) |
| `rbegin()` / `rend()` | Reverse iterators (top → bottom) |
| `begin() const` / `end() const` | Const iterator overloads |

---

## 🏛 **Operating**

### 🔸 **STL containers and algorithms (module theme)**

Module 08 is the first module where STL containers and algorithms are **mandatory**. The goal is to use them instead of reinventing the wheel:

```cpp
#include <vector>
#include <algorithm>

std::vector<int> v;
v.push_back(42);

std::vector<int>::iterator it = std::find(v.begin(), v.end(), 42);
if (it != v.end())
    std::cout << "Found: " << *it << std::endl;
```

**Key headers:** `<vector>`, `<list>`, `<deque>`, `<stack>`, `<algorithm>`, `<numeric>`.

### 🔸 **easyfind — std::find wrapper (ex00)**

`std::find(first, last, value)` returns an iterator to the first match, or `last` if none is found:

```cpp
std::vector<int> numbers;
numbers.push_back(10);
numbers.push_back(42);

std::vector<int>::iterator it = easyfind(numbers, 42);
std::cout << *it << std::endl;  // → 42
```

The evaluation requires using `std::find` — not a manual `while (it != end)` search loop.

### 🔸 **Span — shortest vs longest span (ex01)**

Given stored numbers `{6, 3, 17, 9, 11}`:

* **shortestSpan** → `2` (distance between 9 and 11)
* **longestSpan** → `14` (distance between 3 and 17)

**Shortest span** cannot be computed by simply subtracting the two smallest numbers. After sorting, the minimum gap is always between two **adjacent** elements — use `std::adjacent_difference` + `std::min_element`.

**Longest span** is simply `max − min`, found efficiently with `std::minmax_element`.

### 🔸 **addRange — filling Span without thousands of addNumber calls (ex01)**

```cpp
std::vector<int> source;
// ... fill source with 10 000 numbers ...

Span sp(10000);
sp.addRange(source.begin(), source.end());
```

Uses `std::vector::insert` internally after checking capacity with `std::distance`.

### 🔸 **MutantStack — iterators on a stack (ex02)**

`std::stack` is a **container adapter** — it wraps an underlying container (`deque` by default) but hides iterators. `MutantStack` inherits from `std::stack` and accesses the protected member `c`:

```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

MutantStack<int>::iterator it = mstack.begin();
while (it != mstack.end())
{
    std::cout << *it << std::endl;  // bottom → top: 5, 17
    ++it;
}

std::stack<int> s(mstack);  // works via inheritance
```

Iteration order matches the underlying container (`deque` or `list`), same as iterating a `std::list` with equivalent push operations.

### 🔸 **Templates in .tpp files**

Function and class templates are declared in `.hpp` and defined in `.tpp`, included at the bottom of the header:

```cpp
// easyfind.hpp
template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
```

Non-template code (e.g. `NotFoundException::what()`, `Span` methods) lives in `.cpp` files.

---

## ⚙️ **Compiling and testing**

Each exercise is **independent** and has its own `Makefile`. Compile and run from the exercise directory.

### 🔧 Compiling

| Exercise | Binary | Command |
|----------|--------|---------|
| ex00 | `easyfind` | `cd ex00 && make` |
| ex01 | `span` | `cd ex01 && make` |
| ex02 | `mutantstack` | `cd ex02 && make` |

```bash
make        # compile
make re     # full rebuild
make fclean # remove binary and object files
```

Compiler flags: `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Use and execution

- #### ✅ Exercise 00 — `./easyfind`

  ```bash
  cd ex00 && make && ./easyfind
  ```

  Tests cover: successful search in `vector`, first occurrence with duplicates, value not found, empty container, first/last element, `list` and `deque` containers, negative integers.

- #### ✅ Exercise 01 — `./span`

  ```bash
  cd ex01 && make && ./span
  ```

  Tests cover: subject example (`2` / `14`), full Span exception, span with 0 or 1 number, `addRange` with iterators, overflow on `addRange`, unsorted numbers, duplicates (`shortestSpan = 0`), OCF, 10 000 sequential numbers, 10 000 random numbers.

- #### ✅ Exercise 02 — `./mutantstack`

  ```bash
  cd ex02 && make && ./mutantstack
  ```

  Tests cover: subject example (`top`, `pop`, `size`, iterator `++`/`--`, copy to `std::stack`), empty stack, single element, bottom-to-top order, const iterators, reverse iterators, OCF, modification via iterator, comparison with `std::list`, `MutantStack` with `std::list` as underlying container.

#### Example — subject snippet (ex01)

```cpp
Span sp = Span(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;  // → 2
std::cout << sp.longestSpan() << std::endl;   // → 14
```

---

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="logo C++" width="150">
  <br>
  cpp08
  <br>
</h1>

<h4 align="center"><em>Module C++ 08 — Conteneurs template, itérateurs et algorithmes.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercices-3-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Note-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Sujet</a> |
  <a href="#-aperçu-du-projet">Aperçu</a> •
  <a href="#-architecture-et-organisation-du-code">Architecture</a> •
  <a href="#-fonctionnement">Fonctionnement</a> •
  <a href="#%EF%B8%8F-compilation-et-tests">Compilation</a>
</p>

---

## 📌 **Aperçu du projet**

**cpp08** est le huitième module C++ du Common Core de 42. Il introduit la **STL** (Standard Template Library) : **conteneurs** (`vector`, `list`, `deque`, `stack`…), **itérateurs** et **algorithmes** (`std::find`, `std::sort`, `std::min_element`…).

Contrairement aux modules précédents, l'utilisation des conteneurs et algorithmes STL n'est pas seulement autorisée — elle est **requise** dès que c'est pertinent.

Le projet est découpé en **3 exercices indépendants**. Tout le code respecte le standard **C++98**.

### 1. Exercice 00 — Easy find ✅

Une **fonction template** `easyfind(T& container, int value)` qui :

* Cherche la **première occurrence** de `value` dans un conteneur séquentiel d'entiers
* Utilise **`std::find`** de `<algorithm>` (une boucle manuelle sur les itérateurs n'est pas acceptable)
* Retourne un **itérateur** vers l'élément trouvé
* Lance `NotFoundException` (hérite de `std::exception`) si la valeur est absente
* Fonctionne avec `std::vector`, `std::list`, `std::deque`, etc. (pas de conteneurs associatifs requis)

### 2. Exercice 01 — Span ✅

Une classe **`Span`** qui stocke au maximum **N entiers** et calcule les écarts minimum et maximum entre deux valeurs stockées :

* `Span(unsigned int N)` — capacité fixée à la construction
* `addNumber(int)` — ajoute un entier ; lance `SpanFullException` si plein
* `addRange(begin, end)` — ajoute une plage d'itérateurs en un seul appel (template dans `Span.tpp`)
* `shortestSpan()` — écart minimal entre deux nombres (algorithmes STL : `sort`, `adjacent_difference`, `min_element`)
* `longestSpan()` — écart maximal (`minmax_element`)
* Lance `NoSpanException` si moins de 2 nombres sont stockés
* **Forme canonique orthodoxe** complète

### 3. Exercice 02 — Mutated abomination ✅

Une **classe template** `MutantStack<T, Container>` qui :

* **Hérite de** `std::stack<T, Container>` (conteneur sous-jacent par défaut : `std::deque`)
* Offre toutes les fonctions membre de `std::stack` (`push`, `pop`, `top`, `size`…)
* Ajoute des **itérateurs** (`begin`, `end`, `rbegin`, `rend` + versions `const`) en exposant le membre protégé `c` du conteneur sous-jacent
* Peut être copiée dans un `std::stack` grâce à l'héritage
* **Forme canonique orthodoxe** complète

### Gestion des erreurs ⚠️

| Exercice | Exception | Quand |
|----------|-----------|-------|
| ex00 | `NotFoundException` | Valeur introuvable dans le conteneur |
| ex01 | `SpanFullException` | Ajout au-delà de la capacité N |
| ex01 | `NoSpanException` | `shortestSpan()` / `longestSpan()` avec 0 ou 1 nombre |

Toutes les exceptions héritent de `std::exception` et sont attrapables via `catch (std::exception& e)`.

---

## 📂 **Architecture et organisation du code**

```
cpp08/
├── ex00/   easyfind.hpp + easyfind.tpp + easyfind.cpp — easyfind
├── ex01/   Span.hpp + Span.tpp + Span.cpp — Span
├── ex02/   MutantStack.hpp + MutantStack.tpp — MutantStack<T>
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 Fonction template — `easyfind` (ex00)

| Fonction | Description |
|----------|-------------|
| `easyfind(T& container, int value)` | Retourne un itérateur vers la première occurrence de `value` ; throw si introuvable |

#### 🔹 Classe — `Span` (ex01)

| Méthode | Description |
|---------|-------------|
| `Span(unsigned int maxSize)` | Crée un Span de capacité maximale N |
| `addNumber(int number)` | Ajoute un entier ; throw si plein |
| `addRange(Iterator begin, Iterator end)` | Ajoute plusieurs entiers via une plage d'itérateurs |
| `shortestSpan() const` | Retourne le plus petit écart entre deux nombres stockés |
| `longestSpan() const` | Retourne le plus grand écart entre deux nombres stockés |

#### 🔹 Classe template — `MutantStack<T, Container>` (ex02)

| Méthode | Description |
|---------|-------------|
| `push(val)` / `pop()` / `top()` / `size()` / `empty()` | Héritées de `std::stack` |
| `begin()` / `end()` | Itérateurs sur le conteneur sous-jacent (bas → haut) |
| `rbegin()` / `rend()` | Itérateurs inverses (haut → bas) |
| `begin() const` / `end() const` | Surcharges const des itérateurs |

---

## 🏛 **Fonctionnement**

### 🔸 **Conteneurs et algorithmes STL (thème du module)**

Le module 08 est le premier où les conteneurs et algorithmes STL sont **obligatoires**. L'objectif est de les utiliser plutôt que de tout réimplémenter :

```cpp
#include <vector>
#include <algorithm>

std::vector<int> v;
v.push_back(42);

std::vector<int>::iterator it = std::find(v.begin(), v.end(), 42);
if (it != v.end())
    std::cout << "Trouve : " << *it << std::endl;
```

**Headers clés :** `<vector>`, `<list>`, `<deque>`, `<stack>`, `<algorithm>`, `<numeric>`.

### 🔸 **easyfind — wrapper autour de std::find (ex00)**

`std::find(first, last, value)` retourne un itérateur vers la première correspondance, ou `last` si rien n'est trouvé :

```cpp
std::vector<int> numbers;
numbers.push_back(10);
numbers.push_back(42);

std::vector<int>::iterator it = easyfind(numbers, 42);
std::cout << *it << std::endl;  // → 42
```

L'évaluation exige l'utilisation de `std::find` — pas une boucle manuelle `while (it != end)`.

### 🔸 **Span — shortest vs longest span (ex01)**

Avec les nombres stockés `{6, 3, 17, 9, 11}` :

* **shortestSpan** → `2` (écart entre 9 et 11)
* **longestSpan** → `14` (écart entre 3 et 17)

Le **shortest span** ne peut pas se calculer en soustrayant simplement les deux plus petits nombres. Après tri, l'écart minimal est toujours entre deux éléments **adjacents** — utiliser `std::adjacent_difference` + `std::min_element`.

Le **longest span** est simplement `max − min`, trouvé efficacement avec `std::minmax_element`.

### 🔸 **addRange — remplir un Span sans des milliers d'addNumber (ex01)**

```cpp
std::vector<int> source;
// ... remplir source avec 10 000 nombres ...

Span sp(10000);
sp.addRange(source.begin(), source.end());
```

Utilise `std::vector::insert` en interne après vérification de la capacité avec `std::distance`.

### 🔸 **MutantStack — itérateurs sur une pile (ex02)**

`std::stack` est un **adaptateur de conteneur** — il encapsule un conteneur sous-jacent (`deque` par défaut) mais masque les itérateurs. `MutantStack` hérite de `std::stack` et accède au membre protégé `c` :

```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

MutantStack<int>::iterator it = mstack.begin();
while (it != mstack.end())
{
    std::cout << *it << std::endl;  // bas → haut : 5, 17
    ++it;
}

std::stack<int> s(mstack);  // fonctionne via l'héritage
```

L'ordre d'itération correspond au conteneur sous-jacent (`deque` ou `list`), identique à une `std::list` avec les mêmes opérations push.

### 🔸 **Templates dans des fichiers .tpp**

Les templates de fonctions et de classes sont déclarés dans `.hpp` et définis dans `.tpp`, inclus en fin de header :

```cpp
// easyfind.hpp
template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
```

Le code non-template (ex. `NotFoundException::what()`, méthodes de `Span`) se trouve dans des fichiers `.cpp`.

---

## ⚙️ **Compilation et tests**

Chaque exercice est **indépendant** et possède son propre `Makefile`. Compiler et exécuter depuis le dossier de l'exercice.

### 🔧 Compilation

| Exercice | Binaire | Commande |
|----------|---------|----------|
| ex00 | `easyfind` | `cd ex00 && make` |
| ex01 | `span` | `cd ex01 && make` |
| ex02 | `mutantstack` | `cd ex02 && make` |

```bash
make        # compiler
make re     # recompilation complète
make fclean # supprime binaire et fichiers objets
```

Flags : `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Utilisation et exécution

- #### ✅ Exercice 00 — `./easyfind`

  ```bash
  cd ex00 && make && ./easyfind
  ```

  Tests : recherche réussie dans `vector`, première occurrence avec doublons, valeur absente, conteneur vide, premier/dernier élément, conteneurs `list` et `deque`, entiers négatifs.

- #### ✅ Exercice 01 — `./span`

  ```bash
  cd ex01 && make && ./span
  ```

  Tests : exemple du sujet (`2` / `14`), exception Span plein, span avec 0 ou 1 nombre, `addRange` avec itérateurs, dépassement de capacité, nombres non triés, doublons (`shortestSpan = 0`), OCF, 10 000 nombres séquentiels, 10 000 nombres aléatoires.

- #### ✅ Exercice 02 — `./mutantstack`

  ```bash
  cd ex02 && make && ./mutantstack
  ```

  Tests : exemple du sujet (`top`, `pop`, `size`, itérateurs `++`/`--`, copie vers `std::stack`), pile vide, un seul élément, ordre bas → haut, itérateurs const, itérateurs reverse, OCF, modification via itérateur, comparaison avec `std::list`, `MutantStack` basé sur `std::list`.

#### Exemple — extrait du sujet (ex01)

```cpp
Span sp = Span(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;  // → 2
std::cout << sp.longestSpan() << std::endl;   // → 14
```
