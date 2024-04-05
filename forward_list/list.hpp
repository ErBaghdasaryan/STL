#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP
#include "list.h"

template <typename T>
forward_list<T>::forward_list(const forward_list<T>& rhs) {
    if (rhs.head == nullptr) {
        return;
    }
    this->head = new Node(rhs.head->data);
    Node* tmp = head;
    Node* tmp_rhs = rhs.head;
    tmp_rhs = tmp_rhs->next;
    while (tmp_rhs) {
        tmp->next = new Node(tmp_rhs->data);
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
}

template <typename T>
forward_list<T>::forward_list(forward_list<T>&& rhs) {
    if (rhs.head == nullptr) {
        return;
    }
    this->head = new Node(rhs.head->data);
    Node* tmp = head;
    Node* tmp_rhs = rhs.head;
    tmp_rhs = tmp_rhs->next;
    while (tmp_rhs) {
        tmp->next = new Node(tmp_rhs->data);
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    rhs.clear();
    rhs.head = nullptr;
}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> init) {
    auto it = init.begin();
    this->head = new Node(*it);
    ++it;
    Node* tmp = this->head;
    while (it != init.end()) {
        tmp->next = new Node(*it);
        tmp = tmp->next;
        ++it;
    }
}


template <typename T> 
forward_list<T>::forward_list(T val) {
    head = new Node(val);
}

template <typename T> 
void forward_list<T>::push_front(T val) {
    Node* tmp = new Node(val);
    tmp->next = head;
    head = tmp;
}

template <typename T>
void forward_list<T>::pop_front() {
    Node* tmp = this->head;
    this->head = this->head->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T> 
bool forward_list<T>::empty() {
    return ((this->head) == nullptr);
}

template <typename T>
void forward_list<T>::erase_after(iterator& it1) {
    Node* tmp = this->head;
    while (tmp->data != *(it1)) {
        tmp = tmp->next;
    }
    Node* del = tmp->next;
    tmp->next = del->next;
    delete del;
    del = nullptr;
    

}

template <typename T>
void forward_list<T>::insert_after(iterator& it1, T val) {
    Node* tmp = this->head;
    while (tmp->data != *(it1)) {
        tmp = tmp->next;
    }
    Node* tmp2 = tmp->next;
    tmp->next = new Node(val);
    tmp->next->next = tmp2;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(const forward_list<T>& rhs) {
    if (this->head == rhs.head) {
        return *(this);
    }
    this->clear();
    this->head = new Node(rhs.head->data);
    Node* tmp = head;
    Node* tmp_rhs = rhs.head;
    tmp_rhs = tmp_rhs->next;
    while (tmp_rhs) {
        tmp->next = new Node(tmp_rhs->data);
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    return *(this);
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(forward_list<T>&& rhs) {
    if (this->head == rhs.head) {
        return *(this);
    }
    this->clear();
    this->head = new Node(rhs.head->data);
    Node* tmp = head;
    Node* tmp_rhs = rhs.head;
    tmp_rhs = tmp_rhs->next;
    while (tmp_rhs) {
        tmp->next = new Node(tmp_rhs->data);
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    rhs.clear();
    rhs.head = nullptr;
    return *(this);
}

template <typename T>
void forward_list<T>::clear() {
    if (head == nullptr) {
        return;
    }
    Node* tmp = head;
    while (tmp->next) {
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin() {
    return iterator(this->head);
} 

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin() const {
    return iterator(this->head);
} 

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end() {
    Node* tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp = tmp->next;
    return iterator(tmp);
} 

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end() const {
    Node* tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp = tmp->next;
    return iterator(tmp);
}

template <typename T>
size_t forward_list<T>::size() {
    Node* tmp = this->head;
    int size = 0;
    while (tmp) {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

template <typename T>
const size_t forward_list<T>::size() const {
    Node* tmp = this->head;
    int size = 0;
    while (tmp) {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

template <typename T>
const forward_list<T>& forward_list<T>::operator[](std::size_t ind) const {
    Node* tmp = this->head;
    for (int i = 0; i < this->size(); ++i) {
        ++tmp;
    }
    return tmp;
}

template <typename T>
void forward_list<T>::merge(forward_list<T>& rhs) {
    Node* tmp = rhs.head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = this->head->next;
    this->head->next = rhs.head;
    rhs.head = nullptr;
}

template <typename T>
void forward_list<T>::merge(forward_list<T>&& rhs) {
    Node* tmp = rhs.head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = this->head->next;
    this->head->next = rhs.head;
    rhs.head = nullptr;
}


template <typename T>
forward_list<T>::~forward_list() {
    this->clear();
}


//operator operator<, >, ==, !=

template <typename T>
bool operator<(const forward_list<T>& lhs, forward_list<T>& rhs) {
    if (lhs.size() < rhs.size()) { return true; }
    typename forward_list<T>::iterator lhsIter(lhs.begin());
    typename forward_list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter >= *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;

    }
    return true;
}


template <typename T>
bool operator>(const forward_list<T>& lhs, forward_list<T>& rhs) {
    if (lhs.size() > rhs.size()) { return true; }
    typename forward_list<T>::iterator lhsIter(lhs.begin());
    typename forward_list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter <= *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;

    }
    return true;
}

template <typename T>
bool operator==(const forward_list<T>& lhs, forward_list<T>& rhs) {
    if (lhs.size() != rhs.size()) { return false; }
    typename forward_list<T>::iterator lhsIter(lhs.begin());
    typename forward_list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter != *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;

    }
    return true;
}

template <typename T>
bool operator!=(const forward_list<T>& lhs, forward_list<T>& rhs) {
    if (lhs.size() == rhs.size()) { return false; }
    typename forward_list<T>::iterator lhsIter(lhs.begin());
    typename forward_list<T>::iterator rhsIter(rhs.begin());
    while (lhsIter != lhs.end()) {
        if (*lhsIter == *rhsIter) { return false; }
        ++lhsIter;
        ++rhsIter;

    }
    return true;
}


#endif // FORWARD_LIST_HPP