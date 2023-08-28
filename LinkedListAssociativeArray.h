#ifndef LINKEDLISTASSOCIATIVEARRAY_H
#define LINKEDLISTASSOCIATIVEARRAY_H

#include <iostream>
#include <stdexcept>
#include "Iterator.h"

template<typename KeyType, typename ValueType>
class LinkedListAssociativeArray {
public:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& v) : key(k), value(v), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;

public:
    LinkedListAssociativeArray() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    void insert(const KeyType& key, const ValueType& value) { //вставляє новий вузол з ключем key і значенням value в кінець однозв'язного списку
        Node* newNode = new Node(key, value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(const KeyType& key) {
        if (isEmpty()) {
            return false;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                    if (current == tail) {
                        tail = prev;
                    }
                } else {
                    head = current->next;
                    if (current == tail) {
                        tail = nullptr;
                    }
                }

                delete current;
                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

    bool findMinimum(KeyType& key, ValueType& value) const {
        if (isEmpty()) {
            return false;
        }

        Node* current = head;
        KeyType minKey = current->key;
        ValueType minValue = current->value;

        while (current) {
            if (current->key < minKey) {
                minKey = current->key;
                minValue = current->value;
            }
            current = current->next;
        }

        key = minKey;
        value = minValue;
        return true;
    }

    using Iterator = LinkedListAssociativeArrayIterator<KeyType, ValueType>;

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

#endif
