#pragma once
#include <cstdlib>

template <class T>
class Vector
{
public:

    typedef T * iterator;

    Vector();
    Vector(size_t);
    Vector(size_t, const T &);
    Vector(const Vector<T> &);
    ~Vector();

    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T &);
    void pop_back();

    void reserve(size_t);
    void resize(size_t);

    T & operator[](size_t);
    Vector<T> & operator=(const Vector<T> &);

private:
    size_t _initial_len;
    size_t _size;
    size_t _capacity;
    T * _buffer;
};

