#ifndef LIST_HPP
#define LIST_HPP
#include "d_list.h"

template <typename T>
list<T>::list(const list<T>& rhs) {
    if (!rhs.head) {
        return;
    }
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs != rhs.tail->next) {
        tmp->next = new Node(tmp_rhs->data);
        tmp->next->prev = tmp;
        tmp_rhs = tmp_rhs->next;
        tmp = tmp->next;
    }
    this->tail = tmp;
}

template <typename T>
list<T>::list(list<T>&& rhs) {
    if (!rhs.head) {
        return;
    }
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs != rhs.tail->next) {
        tmp->next = new Node(tmp_rhs->data);
        tmp->next->prev = tmp;
        tmp_rhs = tmp_rhs->next;
        tmp = tmp->next;
    }
    this->tail = tmp;
    rhs.clear();
}


template <typename T>
list<T>::list(std::initializer_list<T> init) {
    auto it = init.begin();
    this->head = new Node(*it);
    ++it;
    Node* tmp = this->head;
    while (it != init.end()) {
        tmp->next = new Node(*it);
        tmp->next->prev = tmp;
        tmp = tmp->next;
        ++it;

    }
    this->tail = tmp;
}

template <typename T>
void list<T>::clear() {
    if (!this->head) {
        return;
    }
    Node* tmp = this->head;
    this->head = head->next;
    while (head != tail->next) {
        delete tmp;
        tmp = this->head;
        head = head->next;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
list<T>::list(const T& rhs) {
    this->head = new Node(rhs);
}

template <typename T>
list<T>::~list() {
    this->clear();
}

template <typename T>
void list<T>::push_back(const T& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        return;
    }
    Node* tmp = this->tail;
    tmp->next = new Node(rhs);
    tmp->next->prev = tmp;
    this->tail = tmp->next;
}

template <typename T>
void list<T>::push_back(T&& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        return;
    }
    Node* tmp = this->tail;
    tmp->next = new Node(rhs);
    tmp->next->prev = tmp;
    this->tail = tmp->next;
}


template <typename T>
void list<T>::pop_back() {
    if (!this->tail) {
        return;
    }
    Node* tmp = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void list<T>::push_front(const T& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        return;
    }
    Node* tmp = this->head;
    this->head->prev = new Node(rhs);
    this->head = this->head->prev;
    head->next = tmp;
}

template <typename T>
void list<T>::push_front(T&& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        return;
    }
    Node* tmp = this->head;
    this->head->prev = new Node(rhs);
    this->head = this->head->prev;
    head->next = tmp;
}

template <typename T>
void list<T>::pop_front() {
    if (!this->head) {
        return;
    }
    Node* tmp = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete tmp;
    tmp = nullptr; 
}

template <typename T>
bool list<T>::empty() {
    return (this->head == nullptr);
}

template <typename T>
list<T>::iterator::iterator(Node* const rhs) {
    this->it = rhs;
}

template <typename T>
list<T>::iterator::iterator(const list<T>::iterator& rhs) {
    this->it = rhs.it;
} 

template <typename T>
list<T>::iterator::iterator(list<T>::iterator&& rhs) {
    this->it = rhs.it;
    rhs.it = nullptr;
} 

template <typename T>
T& list<T>::iterator::operator*() {
    return (this->it->data);   
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator++(int) {
    list<T>::iterator tmp(this->it);
    this->it = this->it->next;
    return tmp;
}

template <typename T>
const typename  list<T>::iterator& list<T>::iterator::operator++() {
    this->it = this->it->next;
    return *this;
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator--(int) {
    list<T>::iterator tmp(this->it);
    this->it = this->it->prev;
    return tmp;
}

template <typename T>
const typename  list<T>::iterator& list<T>::iterator::operator--() {
    this->it = this->it->prev;
    return *this;
}

template <typename T>
bool list<T>::iterator::operator!=(const iterator rhs) {
    return (this->it != rhs.it);
}

template <typename T>
bool list<T>::iterator::operator==(const iterator rhs) {
    return (this->it == rhs.it);
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
    return list<T>::iterator(this->head);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
    return list<T>::iterator(this->tail->next);
}

template <typename T>
typename list<T>::iterator list<T>::begin() const {
    return list<T>::iterator(this->head);
}

template <typename T>
typename list<T>::iterator list<T>::end() const {
    return list<T>::iterator(this->tail->next);
}

template <typename T>
list<T>::iterator::~iterator() {
    this->it = nullptr;
}

template <typename T>
void list<T>::erase(list<T>::iterator input1, list<T>::iterator input2) {
    Node* tmp = this->head;
    while (tmp->data != *input1) {
        tmp = tmp->next;
    }
    Node* tmp_2 = this->tail;
    while (tmp_2->data != *input2) {
        tmp_2 = tmp_2->prev; 
    }
    Node* first = tmp->prev;
    while (tmp != tmp_2) {
        Node* del = tmp;
        tmp = tmp->next;
        delete del;
    }
    first->next = tmp_2;
    tmp_2->prev = first;
}


template <typename T>
void list<T>::erase(list<T>::iterator input1) {
    Node* tmp = this->head;
    while (tmp->data != *input1) {
        tmp = tmp->next;
    }
    tmp->prev->next = tmp->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void list<T>::insert(iterator input, const T& rhs) {
    Node* tmp = this->head;
    while (tmp->data != *input) {
        tmp = tmp->next;
    }
    Node* ins = new Node(rhs);
    ins->next = tmp;
    ins->prev = tmp->prev;
    tmp->prev = ins;
    ins->prev->next = ins;

}

template <typename T>
size_t list<T>::size() {
    int count = 0;
    Node* tmp = this->head;
    while (tmp) {
        tmp = tmp->next;
        ++count;
    }
    return count;
}

template <typename T>
size_t list<T>::size() const {
    int count = 0;
    Node* tmp = this->head;
    while (tmp) {
        tmp = tmp->next;
        ++count;
    }
    return count;
}

template <typename T>
void list<T>::merge(list<T>& rhs) {
    rhs.tail->next = this->head->next;
    this->head->next->prev = rhs.tail;
    this->head->next = rhs.head;
    rhs.head->prev = this->head;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template <typename T>
bool operator<(const list<T>& lhs, const list<T>& rhs) {
    if (lhs.size() > rhs.size()) { return false; }
    typename list<T>::iterator lhsIter(lhs.begin());
    typename list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter >= *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;
    }
    return true;

}


template <typename T>
bool operator>(const list<T>& lhs, const list<T>& rhs) {
    if (lhs.size() < rhs.size()) { return false; }
    typename list<T>::iterator lhsIter(lhs.begin());
    typename list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter <= *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;
    }
    return true;

}

template <typename T>
bool operator==(const list<T>& lhs, const list<T>& rhs) {
    if (lhs.size() != rhs.size()) { return false; }
    typename list<T>::iterator lhsIter(lhs.begin());
    typename list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter != *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;
    }
    return true;

}

template <typename T>
bool operator!=(const list<T>& lhs, const list<T>& rhs) {
    if (lhs.size() == rhs.size()) { return false; }
    typename list<T>::iterator lhsIter(lhs.begin());
    typename list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter == *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;
    }
    return true;

}

#endif // LIST_HPP