#include "string.h"
#include <cstring>

//ctor
String::String(const String& rhs) {
    this->m_size = rhs.m_size;
    this->capacity = rhs.capacity;
    if (this->m_size == capacity) {
        this->resize();
    }
    this->str = new char[this->capacity];
    for (int i = 0; i < (this->m_size); ++i) {
        *(str + i) = *(rhs.str + i);
    }
    *(this->str + this->m_size) = '\0';
}

String::String(String&& rhs) {
    this->m_size = rhs.m_size;
    this->capacity = rhs.capacity;
    this->str = rhs.str;
    rhs.str = nullptr;
}

String::String(const char* rhs) {
    this->capacity = 15;
    this->m_size = strlen(rhs);
    if (this->m_size == capacity) {
        this->resize();
    }
    this->str = new char[this->capacity];
    for (int i = 0; i < (this->m_size); ++i) {
        *(str + i) = *(rhs + i);
    }
}

String::String(const std::string& rhs) {
    this->m_size = rhs.size();
    this->capacity = rhs.capacity();
    this->str = new char[this->capacity];
    for (int i = 0; i < rhs.size(); ++i) {
        *(str + i) = rhs[i];
    }   
    *(str + this->m_size) = '\0';
}

String::~String() {
    this->clear();
}
//

bool String::empty() {
    return (str == nullptr);
}

void String::clear() {
    delete[] str;
    m_size = 0;
    capacity = 0;
}

void String::resize() {
    capacity *= 2;
}

size_t String::size() {
    return this->m_size;
}

void String::push_back(const char& ch) {
    if (m_size == capacity) {
        resize();
    }
    char* tmp = new char[this->capacity];
    for (int i = 0; i < this->m_size; ++i) {
        *(tmp + i) = *(this->str + i);
    }
    *(tmp + m_size) = ch;
    *(tmp + m_size + 1) = '\0';
    delete[] this->str;
    this->str = tmp;
    ++this->m_size;
    tmp = nullptr;
}

void String::pop_back() {
    char* tmp = new char[this->capacity];
    for (int i = 0; i < (this->m_size - 1); ++i) {
        *(tmp + i) = *(this->str + i);
    }
    *(this->str + this->m_size) = '\0';
    --this->m_size;
}

void String::erase(const size_t ind) {
    if (ind < 0) {
        throw::std::invalid_argument("index is low than 0");
        return;
    }
    char* tmp = new char[this->capacity];
    for (int i = 0; i < ind; ++i) {
        *(tmp + i) = *(this->str + i);
    }
    *(tmp + ind) = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    this->m_size -= (ind + 1);
}

void String::erase(const size_t ind, const size_t count) {
    if (ind < 0 || count < 0) {
        throw::std::invalid_argument("Invalid argument");
    }
    char* tmp = new char[this->capacity];
    int i;
    for (i = 0; i < ind; ++i) {
        *(tmp + i) = *(this->str + i);
    }
    int j = i;
    for (int k = ind + count + 1; k < (this->m_size); ++k) {
        *(tmp + j) = *(this->str + k);
        ++j;
    }
    *(tmp + j) = '\0';
    this->m_size -= count;
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;   
}

long String::find(const char& ch) {
    for (int i = 0; i < m_size; ++i) {
        if (*(str + i) == ch) {
            return i;
        }
    }
    return -1;
}

void String::insert(const char& ch, size_t ind) {
    if (ind == m_size) {
        this->push_back(ch);
        return;
    }
    char* tmp = new char[capacity];
    int i;
    for (i = 0; i < ind; ++i) {
        *(tmp + i) = *(this->str + i);
    }
    *(tmp + i) = ch;
    ++i;
    for (int j = i; j < this->m_size; ++j) {
        *(tmp + (i++)) = *(this->str + j);
    }
    ++this->m_size;
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    *(this->str + this->m_size) = '\0';
}

char String::operator[](size_t ind) {
    return *(this->str + ind);
}