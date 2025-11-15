#include "DoublyLinkedList.h"
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), length(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::push_front(int value) {
    Node* node = new Node(value);
    node->next = head;
    node->prev = nullptr;

    if (head) {
        head->prev = node;
    } else {
        // lista była pusta, więc nowy element jest jednocześnie ogonem
        tail = node;
    }

    head = node;
    ++length;
}

void DoublyLinkedList::push_back(int value) {
    Node* node = new Node(value);
    node->prev = tail;
    node->next = nullptr;

    if (tail) {
        tail->next = node;
    } else {
        // lista była pusta, więc nowy element jest jednocześnie początkiem
        head = node;
    }

    tail = node;
    ++length;
}

void DoublyLinkedList::insert_at(int index, int value) {
    if (index <= 0) {
        push_front(value);
        return;
    }
    if (index >= length) {
        push_back(value);
        return;
    }

    // szukamy węzła o danym indeksie
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    Node* newNode = new Node(value);
    Node* prevNode = current->prev;

    newNode->next = current;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    current->prev = newNode;

    ++length;
}

void DoublyLinkedList::pop_front() {
    if (!head) return; // lista pusta

    Node* oldHead = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        // lista stała się pusta
        tail = nullptr;
    }

    delete oldHead;
    --length;
}

void DoublyLinkedList::pop_back() {
    if (!tail) return; // lista pusta

    Node* oldTail = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        // lista stała się pusta
        head = nullptr;
    }

    delete oldTail;
    --length;
}

void DoublyLinkedList::remove_at(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Nieprawidlowy indeks w remove_at");
    }

    if (index == 0) {
        pop_front();
        return;
    }
    if (index == length - 1) {
        pop_back();
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    Node* prevNode = current->prev;
    Node* nextNode = current->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete current;
    --length;
}

void DoublyLinkedList::print_forward() const {
    std::cout << "Lista (od poczatku): ";
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_backward() const {
    std::cout << "Lista (od konca): ";
    Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}

bool DoublyLinkedList::empty() const {
    return length == 0;
}

int DoublyLinkedList::size() const {
    return length;
}

ListIterator DoublyLinkedList::begin() const {
    return ListIterator(head);
}

ListIterator DoublyLinkedList::rbegin() const {
    return ListIterator(tail);
}
