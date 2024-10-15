#include "vector.h"
#include <algorithm>
#include <cassert>

template<class T>
Vector<T>::Vector()
{
    _initial_len = 4;
    _capacity = 4;
    _size = 0;
    _buffer = new T[_initial_len];
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    _size = v._size;
    _capacity = v._capacity;
    _buffer = new T[_size];
    for (int i = 0; i < _size; i++)
        _buffer[i] = v._buffer[i];
}


template<class T>
Vector<T>::Vector(size_t size)
{
    _capacity = size;
    _size = size;
    _buffer = new T[size];
}

template<class T>
Vector<T>::Vector(size_t size, const T & initial)
{
    _size = size;
    _capacity = size;
    _buffer = new T [size];
    for (int i = 0; i < size; i++)
        _buffer[i] = initial;
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
    delete[ ] _buffer;
    _size = v._size;
    _capacity = v._capacity;
    _buffer = new T [_size];
    for (int i = 0; i < _size; i++)
        _buffer[i] = v._buffer[i];
    return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return _buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return _buffer + _size;
}

template<class T>
T& Vector<T>::front()
{
    return _buffer[0];
}

template<class T>
T& Vector<T>::back()
{
    return _buffer[_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (_size == _capacity)
        reserve(size_t(_capacity * 1.6));
    _buffer [_size] = v;
    _size++;
}

template<class T>
void Vector<T>::pop_back()
{
    _size--;
}

template<class T>
void Vector<T>::reserve(size_t capacity)
{
    if (capacity <= _capacity) return;

    T * new_buffer = new T [capacity];
    assert(new_buffer);
    std::copy(new_buffer, new_buffer + _size, _buffer);
    _capacity = capacity;
    delete[] _buffer;
    _buffer = new_buffer;
}


template<class T>
size_t Vector<T>::size()const
{
    return _size;
}

template<class T>
void Vector<T>::resize(size_t size)
{
    reserve(size);
    _size = size;
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
    return _buffer[index];
}

template<class T>
Vector<T>::~Vector()
{
    delete[] _buffer;
}

