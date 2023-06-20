#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cassert>
#include <algorithm>


constexpr int initialCapacity{ 4 };

template <typename T>
class dynamicArray
{
private:
    int m_size{ 0 };                    // How many elements are in array
    int m_capacity{ initialCapacity };  // How big array is internally
    T* m_arr{ nullptr };

    T* allocateArray();
    void expandArray();

public:
    dynamicArray(const int size = 0);
    dynamicArray(const int size, const T value);
    dynamicArray(std::initializer_list<T> iList);
    ~dynamicArray();
    dynamicArray(const dynamicArray& other);
    dynamicArray& operator=(const dynamicArray& other);
    dynamicArray(dynamicArray&& other) noexcept;
    dynamicArray& operator=(dynamicArray&& other) noexcept;

    T& operator[](const int index);
    const T& operator[](const int index) const;
    void append(const T elem); //insert at the end
    void insert(const T elem, const int index);
    int size() const;
};

template <typename T>
dynamicArray<T>::dynamicArray(const int size) : m_size{ size }
{
    if (m_size < 0)
        throw std::invalid_argument("Array size cannot be negative.");
    if (m_size > m_capacity)
        m_capacity = m_size + 2;
    m_arr = allocateArray();
}

template <typename T>
dynamicArray<T>::dynamicArray(const int size, const T value) : dynamicArray(size)
{
    std::fill_n(m_arr, size, value);
}

template <typename T>
dynamicArray<T>::dynamicArray(std::initializer_list<T> iList) : dynamicArray(static_cast<int>(iList.size()))
{
    for (int i{ 0 }; const auto& elem : iList)
    {
        m_arr[i++] = elem;
    }
}

template <typename T>
dynamicArray<T>::~dynamicArray()
{
    delete[] m_arr;
}

template <typename T>
dynamicArray<T>::dynamicArray(const dynamicArray& other) : dynamicArray(other.m_size)
{
    for (int i = 0; i < other.m_size; i++)
    {
        m_arr[i] = other[i];
    }
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
dynamicArray<T>::dynamicArray(dynamicArray&& other) noexcept
{
    m_arr = other.m_arr;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    
    other.m_arr = nullptr;
}

template <typename T>
dynamicArray<T>& dynamicArray<T>::operator=(dynamicArray&& other) noexcept
{
    delete[] m_arr;
    m_arr = other.m_arr;
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    other.m_arr = nullptr;
    return *this;
}

template <typename T>
T* dynamicArray<T>::allocateArray()
{
    return new T[m_capacity]{};
}

template <typename T>
void dynamicArray<T>::expandArray()
{
    //assert(m_capacity != 0 && "Array capacity is zero during expansion!");
    if (m_capacity == 0)
        throw std::runtime_error("Array capacity is zero during expansion!");
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
void dynamicArray<T>::append(const T elem)
{
    // out of memory, expand array
    if (m_size == m_capacity)
    {
        expandArray();
    }

    m_arr[m_size++] = elem;
}

template <typename T>
void dynamicArray<T>::insert(const T elem, const int index)
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