#ifndef QUEUE_H
#define QUEUE_H


template <typename T>
class queue {
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node() : data{0}, next{nullptr}, prev{nullptr} {}
        Node(const T& rhs) : data{rhs}, next{nullptr}, prev{nullptr} {}
        Node(T&& rhs) : data{rhs}, next{nullptr}, prev{nullptr} {}
    }*head, *tail;
    std::size_t m_size;

public:

    queue();
    queue(const queue&);
    queue(queue&&);
    ~queue();
public:
    queue& operator=(const queue&);
    queue& operator=(queue&&);

public:
    T& back();
    bool empty();
    T& front();
    void push(const T&);
    void push(T&&);
    void pop();
    std::size_t size();
    void swap(queue&);
private:
    void clear();
};

#endif // QUEUE_H