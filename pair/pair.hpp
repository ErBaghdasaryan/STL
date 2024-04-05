#include "pair.h"



template <typename T1, typename T2>
Pair<T1, T2>::Pair() {
    first = 0;
    second = 0;
}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& arg1, const T2& arg2) {
    first = arg1;
    second = arg2;
}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1&& arg1, T2&& arg2) {
    first = arg1;
    second = arg2;
}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair<T1, T2>& rhs) {
    this->first = rhs.first;
    this->second = rhs.second;
} 

template <typename T1, typename T2> 
Pair<T1, T2>::Pair(Pair<T1, T2>&& rhs) {
    this->first = rhs.first;
    this->second = rhs.second;
}

template <typename T1, typename T2> 
bool Pair<T1, T2>::operator==( const Pair<T1, T2>& rhs) {
    return (this->first == rhs.first) && (this->second == rhs.second);
}