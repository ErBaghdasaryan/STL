#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "queue.h"

template <typename T>
queue<T>::queue() 
:head{nullptr}
, tail{nullptr}
, m_size{0}
{}

template <typename T>
queue<T>::queue(const queue<T>& rhs) {
    if (!rhs.head) {
        return;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data);;
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;   
    }
    this->tail = tmp;
}

template <typename T>
queue<T>::queue(queue<T>&& rhs) {
    if (!rhs.head) {
        return;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data);;
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;   
    }
    this->tail = tmp;
    rhs.clear();
    rhs.m_size = 0;
}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& rhs) {
    if (!rhs.head) {
        return *this;
    }
    if (this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data);;
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;   
    }
    this->tail = tmp;
}

template <typename T>
queue<T>& queue<T>::operator=(queue<T>&& rhs) {
    if (!rhs.head) {
        return *this;
    }
    if (this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->head = new Node(rhs.head->data);
    Node* tmp = this->head;
    Node* tmp_rhs = rhs.head->next;
    while (tmp_rhs) {
        Node* newNode = new Node(tmp_rhs->data);;
        tmp->next = newNode;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        tmp_rhs = tmp_rhs->next;   
    }
    this->tail = tmp;
    rhs.clear();
    rhs.m_size = 0;
}

template <typename T>
queue<T>::~queue() {
    if (!this->head) {
        return ;
    }
    this->clear();
}


template <typename T>
bool queue<T>::empty() {
    return this->m_size == 0;
}

template <typename T>
T& queue<T>::back() {
    return this->tail->data;
}

template <typename T>
T& queue<T>::front() {
    return this->head->data;
}

template <typename T>
void queue<T>::push(const T& rhs) {
    if (!this->head) {
        Node* newNode = new Node(rhs);
        this->head = newNode;
        this->tail = newNode;
        ++this->m_size;
        return ;
    }
    this->tail->next = new Node(rhs);
    this->tail->next->prev = this->tail;
    this->tail = this->tail->next;
    ++this->m_size;
}

template <typename T>
void queue<T>::push(T&& rhs) {
    if (!this->head) {
        Node* newNode = new Node(rhs);
        this->head = newNode;
        this->tail = newNode;
        ++this->m_size;
        return ;
    }
    this->tail->next = new Node(rhs);
    this->tail->next->prev = this->tail;
    this->tail = this->tail->next;
    ++this->m_size;
}

template <typename T>
void queue<T>::pop() {
    Node* newNode = this->head;
    this->head = this->head->next;
    delete newNode;
    newNode = nullptr;
}

template <typename T>
void queue<T>::swap(queue<T>& rhs) {
    std::swap(this->head, rhs.head);
    std::swap(this->tail, rhs.tail);
}

template <typename T>
void queue<T>::clear() {
    if (!this->head) {
        return;
    }
    Node* tmp;
    while (this->head) {
        tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
    tmp = nullptr;
    this->m_size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

#endif // QUEUE_HPP