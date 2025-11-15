#pragma once
#include <stdexcept>
#include "Node.h"

/**
 * @file ListIterator.h
 * @brief Definicja iteratora do listy dwukierunkowej.
 */

/**
 * @class ListIterator
 * @brief Prosty iterator po liście dwukierunkowej.
 *
 * Umożliwia poruszanie się po liście do przodu i do tyłu,
 * oraz odczyt aktualnej wartości.
 */
class ListIterator {
public:
    /**
     * @brief Tworzy iterator niewskazujący na żaden element.
     */
    ListIterator() = default;

    /**
     * @brief Tworzy iterator ustawiony na dany węzeł.
     * @param start Wskaźnik na węzeł, od którego rozpoczyna się iteracja.
     */
    explicit ListIterator(Node* start);

    /**
     * @brief Sprawdza, czy iterator wskazuje na poprawny węzeł.
     * @return true jeśli aktualny węzeł nie jest nullptr.
     */
    bool isValid() const;

    /**
     * @brief Zwraca wartość aktualnego elementu.
     * @return Wartość typu int przechowywana w węźle.
     * @throws std::out_of_range jeśli iterator nie wskazuje na żaden element.
     */
    int get() const;

    /**
     * @brief Sprawdza, czy istnieje następny element.
     * @return true jeśli istnieje węzeł po prawej stronie.
     */
    bool hasNext() const;

    /**
     * @brief Sprawdza, czy istnieje poprzedni element.
     * @return true jeśli istnieje węzeł po lewej stronie.
     */
    bool hasPrev() const;

    /**
     * @brief Przechodzi do następnego elementu listy.
     *
     * Jeżeli aktualny węzeł jest nullptr, nic się nie dzieje.
     */
    void next();

    /**
     * @brief Przechodzi do poprzedniego elementu listy.
     *
     * Jeżeli aktualny węzeł jest nullptr, nic się nie dzieje.
     */
    void prev();

private:
    Node* current{nullptr}; ///< Wskaźnik na aktualny węzeł (nullptr = poza listą).

    friend class DoublyLinkedList;
};
