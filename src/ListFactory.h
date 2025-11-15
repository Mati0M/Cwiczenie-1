#pragma once
#include "DoublyLinkedList.h"

/**
 * @file ListFactory.h
 * @brief Definicja fabryki do tworzenia list dwukierunkowych.
 */

/**
 * @class ListFactory
 * @brief Prosta fabryka list dwukierunkowych.
 *
 * Wzorzec Factory – ukrywa szczegóły tworzenia obiektu listy
 * i zawsze zwraca listę zaalokowaną na stercie (przez new).
 */
class ListFactory {
public:
    /**
     * @brief Tworzy nową listę dwukierunkową na stercie.
     * @return Wskaźnik na nową listę (należy później wywołać delete).
     */
    static DoublyLinkedList* createList();
};
