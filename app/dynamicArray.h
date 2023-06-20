#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>


constexpr int initialCapacity{ 4 };

template <typename T>
class dynamicArray
{
private:
    int m_size{ 0 }; //How many elements are in array
    int m_capacity{ initialCapacity }; //How big array is internally
    T* m_arr{ nullptr };

    T* allocateArray();
    void expandArray();

public:
    dynamicArray(int size = initialCapacity);
    dynamicArray(std::initializer_list<T> iList);
    ~dynamicArray();
    dynamicArray(const dynamicArray&) = delete; // to avoid shallow copy
    dynamicArray& operator=(const dynamicArray& other);

    T& operator[](const int index);
    const T& operator[](const int index) const;
    void append(T elem); //insert at the end
    void insert(T elem, int index);
    int size() const;
};

template <typename T>
dynamicArray<T>::dynamicArray(int size) : m_capacity{ size }
{
    if (size <= 0)
        throw std::invalid_argument("Array size is 0 or less.");
    m_arr = allocateArray();
}

template <typename T>
dynamicArray<T>::dynamicArray(std::initializer_list<T> iList) : dynamicArray(static_cast<int>(iList.size()))
{
    for (const auto& elem : iList)
    {
        this->append(elem);
    }
}

template <typename T>
dynamicArray<T>::~dynamicArray()
{
    delete[] m_arr;
}

template<typename T>
dynamicArray<T>& dynamicArray<T>::operator=(const dynamicArray& other)
{
    // Guard self assignment
    if (this == &other)
        return *this;

    // Check can we just reuse the existing space
    if (m_size != other.m_size)
    {
        m_capacity = other.m_capacity;
        T* tempArr = allocateArray();
        delete[] m_arr;
        m_arr = tempArr;
    }

    for (int i = 0; i < other.m_size; i++)
    {
        m_arr[i] = other[i];
    }
    m_size = other.m_size;

    return *this;
}

template <typename T>
T* dynamicArray<T>::allocateArray()
{
    return new T[m_capacity];
}

template <typename T>
void dynamicArray<T>::expandArray()
{
    m_capacity *= 2;
    T* tempArr = allocateArray();

    for (int i = 0; i <= m_size; i++)
    {
        tempArr[i] = m_arr[i];
    }
    
    delete[] m_arr;
    m_arr = tempArr;
}

template <typename T>
T& dynamicArray<T>::operator[](const int index)
{
    // prevent buffer overflow attack
    if ((index < 0) || (index > m_size))
        throw std::out_of_range("Out of array bounds");
    return m_arr[index];
}

template <typename T>
const T& dynamicArray<T>::operator[](const int index) const
{
    // prevent buffer overflow attack
    if ((index < 0) || (index > m_size))
        throw std::out_of_range("Out of array bounds");
    return m_arr[index];
}

template <typename T>
void dynamicArray<T>::append(T elem)
{
    // out of memory, expand array
    if (m_size == m_capacity)
    {
        expandArray();
    }

    m_arr[m_size++] = elem;
}

template <typename T>
void dynamicArray<T>::insert(T elem, int index)
{
    if ((index < 0) || (index > m_size))
        throw std::out_of_range("Out of array bounds");

    // Do we have enough space?
    if (m_size == m_capacity)
    {
        expandArray();
    }

    // Shift elements from the end
    for (int i = m_size; i > index; i--)
    {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[index] = elem;
    m_size++;
}

template <typename T>
int dynamicArray<T>::size() const
{
    return m_size;
}

#endif /* DYNAMIC_ARRAY_H */