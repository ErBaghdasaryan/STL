#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <initializer_list>
#include <type_traits>
#include <initializer_list>
#include <type_traits>

template <typename T>
class vector {
public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        iterator();
        iterator(T* const);
        iterator(const iterator&);
        iterator(iterator&&);
        ~iterator();
    public:
        iterator& operator=(const iterator&);
        iterator& operator=(const iterator&) const;

    public:
        T& operator*();
        iterator operator+(int);
        iterator operator-(int);
        iterator operator++(int);
        iterator& operator++();
        iterator operator--(int);
        iterator& operator--();
        iterator& operator+=(const int);
        iterator& operator-=(const int);
        iterator& operator*=(const int);
        iterator& operator/=(const int);
        iterator& operator[](const int);
        const iterator& operator[](const int) const;
        bool operator==(const iterator&);
        bool operator!=(const iterator&);

    private:
        T* m_iter;
    };
public:
    vector();
    vector(const vector&);
    vector(vector&&);
    vector(const std::size_t);
    vector(const std::size_t, const T);
    vector(std::initializer_list<T>);
    ~vector();
public:
    vector& operator=(const vector&);
    vector& operator=(vector&&);
public:
    T& operator[](const std::size_t ind);
    const T& operator[](const std::size_t ind) const;
public:
    const std::size_t size() const;
    std::size_t size();
    std::size_t capacity();
    const std::size_t capacity() const;
    iterator begin();
    iterator end();
    void erase(const iterator);
    void erase(iterator, iterator);
    void insert(iterator, const T&);
    void push_back(const T);
    void pop_back();
    void resize(const std::size_t);
    void clear();
    void swap(vector&);
    void resize();
    bool empty();
private:
    std::size_t m_size;
    std::size_t m_capacity;
    T* m_arr;
};

#endif  //VECOTR_H
