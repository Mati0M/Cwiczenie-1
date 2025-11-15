#include "ListIterator.h"

ListIterator::ListIterator(Node* start)
    : current(start) {}

bool ListIterator::isValid() const {
    return current != nullptr;
}

int ListIterator::get() const {
    if (!current) {
        throw std::out_of_range("Iterator nie wskazuje na żaden element (nullptr).");
    }
    return current->data;
}

bool ListIterator::hasNext() const {
    return current && current->next;
}

bool ListIterator::hasPrev() const {
    return current && current->prev;
}

void ListIterator::next() {
    if (current) {
        current = current->next;
    }
}

void ListIterator::prev() {
    if (current) {
        current = current->prev;
    }
}
