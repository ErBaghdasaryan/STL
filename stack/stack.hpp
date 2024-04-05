#ifndef STACK_HPP
#define STACK_HPP
#include "stack.h"

template <typename T>
stack<T>::stack()
: head{nullptr}
, tail{nullptr}
, m_size{0}
{}

template <typename T>
stack<T>::stack(const stack& rhs) {
    if (!rhs.head) {
        return;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data); 
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    this->tail = tmp;
}

template <typename T>
stack<T>::stack(stack&& rhs) {
    if (!rhs.head) {
        return;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data); 
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    this->tail = tmp;
    Node* del;
    while (rhs.head) {
        del = rhs.head;
        rhs.head = rhs.head->next;
        delete del;
    }
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.m_size = 0;
}


template <typename  T>
stack<T>& stack<T>::operator=(const stack<T>& rhs) {
    if (!rhs.head) {
        return *this;
    }
    if (*this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data); 
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    this->tail = tmp;
    return *this;
}


template <typename  T>
stack<T>& stack<T>::operator=(stack<T>&& rhs) {
    if (!rhs.head) {
        return *this;
    }
    if (*this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data); 
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;
    }
    this->tail = tmp;
    Node* del;
    while (rhs.head) {
        del = rhs.head;
        rhs.head = rhs.head->next;
        delete del;
    }
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.m_size = 0;
    return *this;
}
template <typename T>
void stack<T>::push(const T& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        return ;
    }
    Node* tmp = new Node(rhs);
    this->tail->next = tmp;
    tmp->prev = this->tail;
    this->tail = tmp;
    ++this->m_size;
}

template <typename T>
void stack<T>::push(T&& rhs) {
    if (!this->head) {
        Node* tmp = new Node(rhs);
        this->head = tmp;
        this->tail = tmp;
        ++this->m_size;
        return ;
    }
    Node* tmp = new Node(rhs);
    this->tail->next = tmp;
    tmp->prev = this->tail;
    this->tail = tmp;
    ++this->m_size;
}

template <typename T>
void stack<T>::pop() {
    if (!this->tail) {
        return;
    }
    Node* tmp = this->tail;
    this->tail = this->tail->prev;
    delete tmp;
    tmp = nullptr;
    --this->m_size;
}


template <typename T>
const std::size_t stack<T>::size() const {
    return this->m_size;
}

template <typename T>
std::size_t stack<T>::size()  {
    return this->m_size;
}

template <typename T>
void stack<T>::swap(stack& rhs) {
    std::swap(this->head, rhs.head);
    std::swap(this->tail, rhs.tail);

}

template <typename T>
T stack<T>::top() {
    return this->tail->data;
}

template <typename T>
const T stack<T>::top() const {
    return this->tail->data;
}


template <typename T>
bool stack<T>::empty() {
    return (this->m_size == 0);
}

template <typename T>
stack<T>::~stack() {
    if (!this->head) {
        return;
    }
    Node* tmp = this->head;
    while (this->head->next) {
        tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
    tmp = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
}


#endif // STACK_HPP