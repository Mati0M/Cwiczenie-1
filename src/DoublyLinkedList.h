#pragma once
#include <iostream>
#include "Node.h"
#include "ListIterator.h"

/**
 * @file DoublyLinkedList.h
 * @brief Definicja klasy listy dwukierunkowej.
 */

/**
 * @class DoublyLinkedList
 * @brief Implementacja listy dwukierunkowej działającej na stercie.
 *
 * Klasa udostępnia operacje:
 * - dodawanie na początek i koniec,
 * - dodawanie pod wskazany indeks,
 * - usuwanie z początku, końca i spod indeksu,
 * - wyświetlanie listy w obu kierunkach,
 * - czyszczenie listy,
 * - uzyskanie iteratorów na początek i koniec listy.
 */
class DoublyLinkedList {
public:
    /**
     * @brief Tworzy pustą listę.
     */
    DoublyLinkedList();

    /**
     * @brief Niszczy listę i zwalnia wszystkie węzły ze sterty.
     */
    ~DoublyLinkedList();

    /**
     * @brief Dodaje element na początek listy.
     * @param value Wartość nowego elementu.
     */
    void push_front(int value);

    /**
     * @brief Dodaje element na koniec listy.
     * @param value Wartość nowego elementu.
     */
    void push_back(int value);

    /**
     * @brief Dodaje element pod wskazany indeks.
     *
     * Jeżeli index <= 0, element jest dodawany na początek.
     * Jeżeli index >= size(), element jest dodawany na koniec.
     *
     * @param index Indeks, pod który ma zostać wstawiony element (0 = początek).
     * @param value Wartość nowego elementu.
     */
    void insert_at(int index, int value);

    /**
     * @brief Usuwa element z początku listy.
     *
     * Jeżeli lista jest pusta, metoda nic nie robi.
     */
    void pop_front();

    /**
     * @brief Usuwa element z końca listy.
     *
     * Jeżeli lista jest pusta, metoda nic nie robi.
     */
    void pop_back();

    /**
     * @brief Usuwa element spod wskazanego indeksu.
     * @param index Indeks elementu do usunięcia.
     * @throws std::out_of_range jeśli indeks jest spoza zakresu.
     */
    void remove_at(int index);

    /**
     * @brief Wyświetla całą listę od początku do końca.
     *
     * Wypisuje wartości na standardowe wyjście, oddzielone spacjami.
     */
    void print_forward() const;

    /**
     * @brief Wyświetla całą listę od końca do początku.
     *
     * Wypisuje wartości na standardowe wyjście, oddzielone spacjami.
     */
    void print_backward() const;

    /**
     * @brief Usuwa wszystkie elementy z listy.
     *
     * Zwalnia pamięć po wszystkich węzłach.
     */
    void clear();

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true jeśli lista nie zawiera żadnych elementów.
     */
    bool empty() const;

    /**
     * @brief Zwraca liczbę elementów w liście.
     * @return Aktualna długość listy.
     */
    int size() const;

    /**
     * @brief Zwraca iterator ustawiony na pierwszy element listy.
     * @return Iterator wskazujący na początek listy.
     */
    ListIterator begin() const;

    /**
     * @brief Zwraca iterator ustawiony na ostatni element listy.
     * @return Iterator wskazujący na koniec listy.
     */
    ListIterator rbegin() const;

private:
    Node* head;   ///< Wskaźnik na pierwszy węzeł listy.
    Node* tail;   ///< Wskaźnik na ostatni węzeł listy.
    int length;   ///< Aktualna liczba elementów w liście.
};
