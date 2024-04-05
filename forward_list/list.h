#ifndef forward_list_H
#define forward_list_H
#include <iterator>
#include <initializer_list>


template <typename T>
class forward_list {
    struct Node {
        T data;
        Node* next;
        Node() : data{0}, next{nullptr} {}
        Node(T val) :  data{val}, next{nullptr} {}
    }*head;
public:
    forward_list() : head{nullptr} {}
    forward_list(const forward_list&);
    forward_list(forward_list&&);
    forward_list(std::initializer_list<T>);
    forward_list(T);
    ~forward_list();
public:
    class iterator: std::iterator<std::forward_iterator_tag, T> {
    public:
        iterator() : it{nullptr} {}
        iterator(const iterator& rhs) {
            this->it = rhs.it;
        }
        iterator(Node* val) {
            this->it = val;
        }
    public:
        iterator& operator++() {
            this->it = this->it->next;
            return *(this);
        }
        T& operator*() {
            return (this->it->data);
        }
        bool operator!=(const iterator& rhs) {
            return (this->it != rhs.it);
        }
    private:
        Node* it;
    };
public:
    friend std::ostream& operator<<(std::ostream& os, const forward_list& rhs) {
        Node* tmp = rhs.head;
        while (tmp) {
            os << tmp->data << " ";
            tmp = tmp->next;
        }
        os << std::endl;
        return os;
    }
    forward_list& operator=(const forward_list&);
    forward_list& operator=(forward_list&&);
    forward_list& operator[](std::size_t );
    const forward_list& operator[](std::size_t ) const;

public:
    void insert_after(iterator&, T);
    void erase_after(iterator&);
    void clear();
    bool empty();
    size_t size();
    const size_t size() const;
    void push_front(T);
    void pop_front();
    iterator begin();
    iterator end();
    iterator begin() const ;
    iterator end() const ;
    void merge(forward_list&);
    void merge(forward_list&&);

};



#endif // forward_list_H