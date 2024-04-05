#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
struct Pair
{
public:
    Pair();
    Pair(const T1&, const T2&);
    Pair(T1&&, T2&&);
    Pair(const Pair&);
    Pair(Pair&&);
public:
    bool operator==(const Pair<T1, T2>&);
public:
   T1 first;
   T2 second;
};

#endif // PAIR_H