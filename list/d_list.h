#ifndef D_LIST_H
#define D_LIST_H

#include <iterator>
#include <initializer_list>
template <typename T>
class list {
    struct Node
    {
        Node* prev;
        T data;
        Node* next;
        Node() : prev{nullptr}, next{nullptr}, data{0} {}
        Node(T val) : prev{nullptr}, next{nullptr}, data{val} {}
    }*head,*tail;
public:
    list() : head{nullptr}, tail{nullptr} {}
    list(const list&);
    list(list&&);
    list(const T& data);
    list(std::initializer_list<T>);
    ~list();
public:
    class iterator : std::iterator<std::bidirectional_iterator_tag, T> {
    public:
        iterator() : it{nullptr} {}
        iterator(const iterator& );
        iterator(iterator&&);
        iterator(Node* const);
        ~iterator();
    public:
        T& operator*();
        iterator operator++(int);
        const iterator& operator++();
        iterator operator--(int);
        const iterator& operator--();
        bool operator!=(const iterator);
        bool operator==(const iterator);
    private:
        Node* it;
    };
public:
    list& operator=(const list&);
    list& operator=(list&&);
public:
    void push_back(const T&);
    void push_back(T&&);
    void pop_back();  
    void push_front(const T&);
    void push_front(T&&);
    void pop_front();
    bool empty();
    void clear();
    iterator begin();
    iterator end();
    iterator begin() const;
    iterator end() const;
    void erase(iterator, iterator);
    void erase(iterator);
    void insert(iterator, const T& );
    size_t size();
    size_t size() const;
    void merge(list&);
    void merge(list&&);
};

#endif  //D_LIST_H
