#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "vector.h"

template <typename T>
vector<T>::vector()
: m_arr{nullptr}
, m_size{0}
, m_capacity{1}
{}

template <typename T>
vector<T>::vector(std::initializer_list<T> init) {
    this->m_size = init.size();
    this->m_capacity = init.size() * 2;
    this->m_arr = new T[this->m_capacity];
    int i = 0;
    for (auto it : init) {
        this->m_arr[i++] = it;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& rhs) {
    this->m_size = rhs.m_size;
    this->m_capacity = rhs.m_capacity;
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs.m_arr[i];
    }
}

template <typename T>
vector<T>::vector(vector<T>&& rhs) {
    this->m_size = rhs.m_size;
    this->m_capacity = rhs.m_capacity;
    this->m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
}

template <typename T>
vector<T>::vector(const std::size_t sz) {
    this->m_size = sz;
    this->m_capacity = sz * 2;
    this->m_arr = new T[this->capacity];
}

template <typename T>
vector<T>::vector(const std::size_t sz, const T arg) {
    this->m_size = sz;
    this->m_capacity = sz * 2;
    this->m_arr = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = arg;
    }
}



template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& rhs) {
    if (*this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->m_capacity = rhs.m_capacity;
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& rhs) {
    if (*this == &rhs) {
        return *this;
    }
    this->m_size = rhs.m_size;
    this->m_capacity = rhs.m_capacity;
    this->m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
}

template <typename T>
vector<T>::~vector() {
    this->clear();
}

template <typename T>
const T& vector<T>::operator[](const std::size_t ind) const {
    return this->m_arr[ind];
}



template <typename T>
T& vector<T>::operator[](const std::size_t ind) {
    return this->m_arr[ind];
}

template <typename T>
std::size_t vector<T>::size() {
    return this->m_size;
}

template <typename T>
const std::size_t vector<T>::size() const {
    return this->m_size;
}

template <typename T>
std::size_t vector<T>::capacity() {
    return this->m_capacity;
}

template <typename T>
const std::size_t vector<T>::capacity() const {
    return this->m_capacity;
}

template <typename T>
void vector<T>::clear() {
    delete[] m_arr;
    this->m_arr = nullptr;
    this->m_size = 0;
    this->m_capacity = 0;
}

template <typename T>
void vector<T>::resize(const std::size_t newSize) {
    T* tmp = new T[newSize]{0};
    for (int i = 0; i < newSize; ++i) {
        tmp[i] = this->m_arr[i];
    }
    delete[] this->m_arr;
    this->m_arr = tmp;
    this->m_size = newSize;
    this->m_capacity = newSize * 2;
    tmp = nullptr;
}

template <typename T>
void vector<T>::pop_back() {
    T* tmp = new T[this->m_size - 1];
    for (int i = 0; i < this->m_size; ++i) {
        tmp[i] = this->m_arr[i]; 
    }
    --this->m_size;
    delete[] this->m_arr;
    this->m_arr = tmp;
    tmp = nullptr;
}

template <typename T>
void vector<T>::push_back(const T arg) {
    if (this->m_size == this->m_capacity) {
        this->resize();
    }
    T* tmp = new T[this->m_size + 1];
    for (int i = 0; i < this->m_size; ++i) {
        tmp[i] = this->m_arr[i];
    }
    tmp[this->m_size] = arg;
    delete[] this->m_arr;
    this->m_arr = tmp;
    tmp = nullptr;
    ++this->m_size;
}

template <typename T>
void vector<T>::resize() {
    this->m_capacity *= 2;
    T* tmp = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; ++i) {
        tmp[i] = this->m_arr[i];
    }
    delete[] this->m_arr;
    this->m_arr = tmp;
    tmp = nullptr;
}


template <typename T>
void vector<T>::swap(vector<T>& rhs) {
    std::swap(this->m_size, rhs.m_size);
    std::swap(this->m_capacity, rhs.m_capacity);
    std::swap(this->m_arr, rhs.m_arr);
}

template <typename T>
void vector<T>::erase(const vector<T>::iterator input1, vector<T>::iterator input2) {
    if (this->m_size >= this->m_capacity) {
        this->resize();
    }

    T* tmp = new T[m_capacity];
    int tmp_size = 0;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (it == input1) {
            while (it != input2) { ++it; }
            if (it == this->end()) { break ;}
        }
        tmp[tmp_size++] = *it;
    }
    this->clear();
    this->m_size = tmp_size;
    this->m_arr = tmp;
    tmp = nullptr;
}

template <typename T>
void vector<T>::erase(const iterator input) {
    if (this->m_size == this->m_capacity) {
        this->resize();
    }
    T* tmp = new T[this->m_capacity];
    int tmp_size = 0;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (it == input) {
            continue;
        }
        tmp[tmp_size++] = *it;
    }
    this->clear();
    this->m_size = tmp_size;
    this->m_arr = tmp;
    tmp = nullptr;
}


template <typename T>
void vector<T>::insert(vector<T>::iterator it1, const T& val) {
    if (it1 == this->end()) {
        this->push_back(val);
        return;
    }
    if ((this->m_size + 1) >= this->m_capacity) {
        this->resize();
    }
    T* tmp = new T[this->m_capacity];
    int i = 0;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (it == it1) {
            tmp[i++] = val;
        }
        tmp[i++] = *it;
    }
    this->clear();
    this->m_size = i;
    this->m_arr = tmp;
}

template <typename T>
bool vector<T>::empty() {
    return (this->m_arr == nullptr);
}



template <typename T>
vector<T>::iterator::iterator()
: m_iter{nullptr}
{}

template <typename T>
vector<T>::iterator::iterator(const iterator& rhs) {
    this->m_iter = rhs.m_iter;
}

template <typename T>
vector<T>::iterator::iterator(iterator&& rhs) {
    this->m_iter = rhs.m_iter;
    rhs.m_iter = nullptr;
}

template <typename T>
vector<T>::iterator::iterator(T* const rhs) {
    this->m_iter = rhs;
}

template <typename T>
vector<T>::iterator::~iterator() {
    this->m_iter = nullptr;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator& rhs) {
    this->m_iter = rhs.m_iter;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator& rhs) const {
    this->m_iter = rhs.m_iter;
    return *this;

}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
    return vector<T>::iterator((this->m_arr));
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
    return vector<T>::iterator((this->m_arr + m_size));
}

template <typename T>
T& vector<T>::iterator::operator*() {
    return *(this->m_iter);
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++() {
    this->m_iter += 1;
    return *(this);
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int) {
    vector<T>::iterator tmp(this->m_iter);
    ++this->m_iter;
    return tmp;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--() {
    this->m_iter -= 1;
    return *(this);
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator--(int) {
    vector<T>::iterator tmp(this->m_iter);
    --this->m_iter;
    return tmp;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator+=(const int rhs) {
    this->m_iter += rhs;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator-=(const int rhs) {
    this->m_iter -= rhs;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator*=(const int rhs) {
    this->m_iter *= rhs;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator+(const int rhs) {
    vector<T>::iterator tmp(this->m_iter + rhs);
    return tmp;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator-(const int rhs) {
    vector<T>::iterator tmp(this->m_iter - rhs);
    return tmp;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator/=(const int rhs) {
    this->m_iter /= rhs;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator[](const int ind) {
    return *(this->m_iter + ind);
}

template <typename T>
const typename vector<T>::iterator& vector<T>::iterator::operator[](const int ind)  const {
    return *(this->m_iter + ind);
}


template <typename T>
bool vector<T>::iterator::operator==(const vector<T>::iterator& rhs) {
    return (this->m_iter) == (rhs.m_iter);
}


template <typename T>
bool vector<T>::iterator::operator!=(const vector<T>::iterator& rhs) {
    return (this->m_iter) != (rhs.m_iter);
}



#endif //VECTOR_HPP
