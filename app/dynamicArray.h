#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>


#define INITIAL_CAPACITY 4

template <class T>
class dynamicArray
{
private:
    int m_size = 0; //How many elements are in array
    int m_capacity = INITIAL_CAPACITY; //How big array is internally
    T* m_arr = nullptr;

    T* allocateArray();
    void expandArray();

public:
    dynamicArray();
    dynamicArray(int size);
    ~dynamicArray();

    T operator[](int index);
    void append(T elem); //insert at the end
    void insert(T elem, int index);
    int size();
};

template <class T>
dynamicArray<T>::dynamicArray()
{
    m_arr = allocateArray();
}

template <class T>
dynamicArray<T>::dynamicArray(int size)
{
    if (size <= 0)
        throw std::invalid_argument("Array size is 0 or less.");
    m_capacity = size;
    m_arr = allocateArray();
}

template <class T>
dynamicArray<T>::~dynamicArray()
{
    free(m_arr);
}

template <class T>
T* dynamicArray<T>::allocateArray()
{
    void* tok = malloc(m_capacity * sizeof(T));
    if (tok == NULL)
        throw std::out_of_range("Failed to allocate memory when expanding array.");
    return (T*)tok;
}

template <class T>
void dynamicArray<T>::expandArray()
{
    m_capacity = m_capacity * 2;
    T* temp_arr = allocateArray();

    for (int i = 0; i <= m_size; i++)
    {
        temp_arr[i] = m_arr[i];
    }
    free(m_arr);
    m_arr = temp_arr;
}

template <class T>
T dynamicArray<T>::operator[](int index)
{
    // prevent buffer overflow attack
    if ((index < 0) || (index > m_capacity))
        throw std::out_of_range("Out of array bounds");
    return m_arr[index];
}

template <class T>
void dynamicArray<T>::append(T elem)
{
    // out of memory, expand array
    if (m_size == m_capacity)
    {
        expandArray();
    }

    m_arr[m_size] = elem;
    m_size++;
}

template <class T>
void dynamicArray<T>::insert(T elem, int index)
{
    // out of memory, expand array
    while (index >= m_capacity)
    {
        expandArray();
    }

    m_arr[index] = elem;
    if (index > m_size)
        m_size = index;
}

template <class T>
int dynamicArray<T>::size()
{
    return m_size;
}

#endif /* DYNAMIC_ARRAY_H */