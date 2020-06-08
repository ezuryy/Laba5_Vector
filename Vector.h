#pragma once
#ifndef LABA5_1_VECTOR_H
#define LABA5_1_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

template<class T>
class Vector {
    int Len, Cap;
    T *Data;
public:
    Vector() : Len(0), Cap(0), Data(nullptr) {};

    Vector(const int &num);

    Vector(const int &num, const T *vec);

    Vector(const Vector &vector);

    ~Vector();

    Vector<T> &operator=(const Vector &vector);

    T operator[](const int &num);

    T at(const int &pos);

    T front();

    T back();

    T *data();

    bool empty();

    int size();

    void reserve(const int &cap);

    int capacity();

    void clear();

    void insert(const int &pos, const T &val);

    void erase(const int &pos);

    void erase(const int &pos1, const int &pos2);

    void push_back(const T &val);

    void pop_back();

    void resize(const int &size);

    void swap(Vector &oth);

    void print();
};

#endif //LABA5_1_VECTOR_H
