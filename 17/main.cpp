#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

#include "Array2d.h"

template <typename T>
class MyVector
{
protected:
    struct Iterator
    {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = value_type*;
        using reference         = value_type&;

        Iterator(pointer ptr) : m_ptr(ptr) { }
        explicit Iterator(long int ptr) : m_ptr((pointer)ptr) { }

        reference operator*() const
        {
            return *m_ptr;
        }

        // pointer operator->()
        // {
        //     return m_ptr;
        // }

        Iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator it = *this;
            ++(*this);
            return it;
        }

        bool operator==(const Iterator& otherIt)
        {
            return m_ptr == otherIt.m_ptr;
        }

        bool operator!=(const Iterator& otherIt)
        {
            return !(*this == otherIt);
        }

        auto operator-(const Iterator& otherIt)
        {
            return this->m_ptr - otherIt.m_ptr;
        }

    private:
        pointer m_ptr;
    };

public:

    T* m_data;
    size_t m_size;

public:
    MyVector() : m_data(nullptr), m_size(0) { }
    MyVector(const std::initializer_list<T>& il)
    {
        m_size = il.size();
        m_data = new T[m_size];

        for(auto i = il.begin(); i < il.end(); ++i)
            m_data[std::distance(il.begin(), i)] = *i;
    }


    MyVector(const MyVector& cpMyVector)
    { 
        m_size = cpMyVector.m_size;
        m_data = new T[m_size];
        std::copy(cpMyVector.begin(), cpMyVector.end(), this->begin());
    }

    MyVector(MyVector&& cpMyVector) : MyVector()
    { 
        swap(cpMyVector);
    }

    Iterator begin() const
    {
        return Iterator(m_data);
    }

    Iterator end() const
    {
        return Iterator(m_data + m_size);
    }

    T& operator[](size_t index)
    {
        return m_data[index];
    }

    MyVector& operator=(const MyVector& cpMyVector)
    {
        if (m_data)
            delete[] m_data;
        m_size = cpMyVector.m_size;
        m_data = new T[m_size];
        std::copy(cpMyVector.begin(), cpMyVector.end(), this->begin());

        return *this;
    }

    MyVector& operator=(MyVector&& otherMyVector)
    {
        if (m_data)
            delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        swap(otherMyVector);

        return *this;
    }

    T& at(size_t index)
    {
        if (index >= m_size)
            throw std::out_of_range("Index out of range");
        return m_data[index];
    }

    T* data()
    {
        return m_data;
    }

    size_t size()
    {
        return m_size;
    }

    void push_back(T value)
    {
        size_t temp_size = m_size + 1;
        T* temp_data = new T[temp_size];

        memcpy(temp_data, m_data, sizeof(T) * m_size);
        temp_data[temp_size - 1] = value;

        if (m_data)
            delete[] m_data;
        m_data = temp_data;
        m_size = temp_size;
    }

    void swap(MyVector& otherMV)
    {
        std::swap(this->m_data, otherMV.m_data);
        std::swap(this->m_size, otherMV.m_size);
    }

    ~MyVector()
    {
        if (m_data)
            delete[] m_data;
    }
};






int main()
{
    // MyVector MV({1, 2, 3, 4});
    // auto it = MV.begin();
    
    // // std::cout << *it << std::endl;
    // // std::cout << *(it++) << std::endl;
    // // std::cout << *(it) << std::endl;
    // // std::cout << *(it++) << std::endl;
    // // std::cout << *((it++)++) << std::endl;
    // // std::cout << *it << std::endl;

    // MyVector cpMV(MV);
    // cpMV[0] = 999;
    // for(auto i : cpMV)
    //     std::cout << i << std::endl;

    // std::cout << "-----------" << std::endl;

    // MyVector<int> newMV;

    // newMV.push_back(5);

    // for(auto i : newMV)
    //     std::cout << i << std::endl;

    // std::cout << "----------------------------" << std::endl;

    // // newMV.swap(cpMV);

    // for(auto i : cpMV)
    //     std::cout << i << std::endl;
    // std::cout << "-----------" << std::endl;

    // for(auto i : newMV)
    //     std::cout << i << std::endl;

    // std::cout << "----------------------------" << std::endl;

    // MyVector<int> newMovedMV(std::move(cpMV));

    // for(auto i : cpMV)
    //     std::cout << i << std::endl;

    // for(auto i : newMovedMV)
    //     std::cout << i << std::endl;

    // std::cout << "----------------------------" << std::endl;
    // for(auto i : newMV)
    //     std::cout << i << std::endl;
    //         std::cout << "-----------" << std::endl;

    // for(auto i : newMovedMV)
    //     std::cout << i << std::endl;
    // newMV = std::move(newMovedMV);

    // for(auto i : newMV)
    //     std::cout << i << std::endl;
    //         std::cout << "-----------" << std::endl;

    // for(auto i : newMovedMV)
    //     std::cout << i << std::endl;

    Array2D<int, 2, 3> arr2d;
    arr2d(0, 0) = 5;
    std::cout << arr2d(0, 0) << std::endl;

    std::fill(arr2d.begin(), arr2d.end(), 10);
    std::copy(std::begin(arr2d), std::end(arr2d), 
              std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    std::cout << arr2d;
    Array2D arr2dMOVED = std::move(arr2d);
    std::cout << arr2d;
}