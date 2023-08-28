#ifndef ITERATOR_H
#define ITERATOR_H

template<typename KeyType, typename ValueType>
class LinkedListAssociativeArray;
using namespace std;

template<typename KeyType, typename ValueType>
class LinkedListAssociativeArrayIterator {
private:
    typename LinkedListAssociativeArray<KeyType, ValueType>::Node* current;

public:
    LinkedListAssociativeArrayIterator(typename LinkedListAssociativeArray<KeyType, ValueType>::Node* node) : current(node) {}

    bool operator==(const LinkedListAssociativeArrayIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const LinkedListAssociativeArrayIterator& other) const {
        return !(*this == other);
    }

    LinkedListAssociativeArrayIterator& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    ValueType& operator*() const {
        if (!current) {
            throw out_of_range("Iterator is out of range.");
        }
        return current->value;
    }
};

#endif

    LinkedListAssociativeArrayIterator& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    ValueType& operator*() const {
        if (!current) {
            throw out_of_range("Iterator is out of range.");
        }
        return current->value;
    }
};

#endif
