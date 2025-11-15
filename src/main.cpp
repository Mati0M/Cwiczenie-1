#include <iostream>
#include "ListFactory.h"
#include "DoublyLinkedList.h"
#include "ListIterator.h"

/**
 * @file main.cpp
 * @brief Program testujący działanie listy dwukierunkowej.
 *
 * @mainpage Lista dwukierunkowa z fabryką i iteratorem
 *
 * Projekt demonstruje:
 * - implementację listy dwukierunkowej na stercie,
 * - wzorzec projektowy Factory (ListFactory),
 * - wzorzec Iterator (ListIterator),
 * - testowanie wszystkich metod w funkcji main().
 */

/**
 * @brief Funkcja główna programu.
 * @return Kod zakończenia programu (0 = OK).
 */
int main() {
    // Tworzenie listy za pomocą fabryki (wzorzec Factory)
    DoublyLinkedList* lista = ListFactory::createList();

    std::cout << "Dodawanie elementow na koniec: 10, 20, 30\n";
    lista->push_back(10);
    lista->push_back(20);
    lista->push_back(30);
    lista->print_forward();
    lista->print_backward();

    std::cout << "\nDodawanie elementow na poczatek: 5, 0\n";
    lista->push_front(5);
    lista->push_front(0);
    lista->print_forward();
    lista->print_backward();

    std::cout << "\nDodawanie elementu 15 pod indeks 3\n";
    lista->insert_at(3, 15);
    lista->print_forward();
    lista->print_backward();

    std::cout << "\nUsuwanie elementu z poczatku\n";
    lista->pop_front();
    lista->print_forward();

    std::cout << "\nUsuwanie elementu z konca\n";
    lista->pop_back();
    lista->print_forward();

    std::cout << "\nUsuwanie elementu spod indeksu 1\n";
    try {
        lista->remove_at(1);
    } catch (const std::exception& e) {
        std::cout << "Wyjatek: " << e.what() << '\n';
    }
    lista->print_forward();

    // --- Test iteratora: przejście od początku do końca ---
    std::cout << "\nIterowanie po liscie (od poczatku) za pomoca iteratora:\n";
    ListIterator it = lista->begin();
    while (it.isValid()) {
        std::cout << it.get() << " ";
        it.next();
    }
    std::cout << std::endl;

    // --- Test iteratora: przejście od końca do początku ---
    std::cout << "\nIterowanie po liscie (od konca) za pomoca iteratora:\n";
    ListIterator it2 = lista->rbegin();
    while (it2.isValid()) {
        std::cout << it2.get() << " ";
        it2.prev();
    }
    std::cout << std::endl;

    // --- Przyklad "wyswietl nastepny" i "wyswietl poprzedni" ---
    std::cout << "\nPrzyklad wyswietlania nastepnego i poprzedniego elementu:\n";
    it = lista->begin();
    if (it.isValid()) {
        std::cout << "Aktualny: " << it.get() << std::endl;

        if (it.hasNext()) {
            it.next();
            std::cout << "Nastepny: " << it.get() << std::endl;
        } else {
            std::cout << "Brak nastepnego elementu.\n";
        }

        if (it.hasPrev()) {
            it.prev();
            std::cout << "Poprzedni: " << it.get() << std::endl;
        } else {
            std::cout << "Brak poprzedniego elementu (bylismy na poczatku listy).\n";
        }
    } else {
        std::cout << "Lista jest pusta.\n";
    }

    std::cout << "\nCzyszczenie calej listy...\n";
    lista->clear();
    lista->print_forward();

    // Zwolnienie pamięci zaalokowanej przez fabrykę
    delete lista;

    return 0;
}
