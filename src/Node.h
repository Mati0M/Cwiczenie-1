#pragma once

/**
 * @file Node.h
 * @brief Definicja węzła listy dwukierunkowej.
 */

/**
 * @class Node
 * @brief Pojedynczy węzeł listy dwukierunkowej.
 *
 * Przechowuje wartość typu int oraz wskaźniki na poprzedni
 * i następny węzeł listy.
 */
class Node {
public:
    int data;   ///< Przechowywana wartość.
    Node* prev; ///< Wskaźnik na poprzedni węzeł (nullptr, jeśli brak).
    Node* next; ///< Wskaźnik na następny węzeł (nullptr, jeśli brak).

    /**
     * @brief Konstruktor tworzący węzeł z daną wartością.
     * @param value Wartość zapisywana w węźle.
     */
    explicit Node(int value);
};
