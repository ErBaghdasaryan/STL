#ifndef STRING_H
#define STRING_H
#include <iostream>
class String {
public:
    String() : str{nullptr}, m_size{0}, capacity{15} {}
    String(const String&);//
    String(String&&);//
    String(const char*);//
    String(const std::string&);
    ~String();//
public:
    char operator[](size_t);
    friend std::ostream& operator<<(std::ostream& os,const String& rhs) {
        if (rhs.str == nullptr) {
            return os;
        }
        for (int i = 0; i < rhs.m_size; ++i) {
            os << *(rhs.str + i);
        }
        return os;
    }
public:
    void insert(const char&, size_t);//
    long find(const char&);//
    void erase(const size_t);//
    void erase(const size_t, const size_t);//
    bool empty();//
    void clear();//
    size_t size();//
    void push_back(const char&);//
    void pop_back();//
    void resize();//
private:
    char* str;
    size_t m_size;
    size_t capacity;
};

#endif // STRING_H