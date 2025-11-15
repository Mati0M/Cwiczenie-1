# Lista dwukierunkowa z fabryką i iteratorem

Projekt w C++ prezentujący:

- implementację listy dwukierunkowej na stercie,
- wzorzec projektowy **Factory** do tworzenia listy (`ListFactory`),
- wzorzec **Iterator** do przechodzenia po elementach (`ListIterator`),
- dokumentację generowaną przez **Doxygen**.

## Struktura projektu

- `Node` – pojedynczy węzeł listy
- `DoublyLinkedList` – właściwa lista dwukierunkowa
- `ListIterator` – iterator po liście
- `ListFactory` – fabryka tworząca nową listę na stercie
- `main.cpp` – test działania wszystkich metod

## Funkcjonalność listy

- dodawanie na początek i koniec,
- dodawanie pod wskazany indeks,
- usuwanie z początku, końca i spod indeksu,
- wyświetlanie listy od początku i od końca,
- czyszczenie całej listy,
- iteracja po liście za pomocą iteratora.
