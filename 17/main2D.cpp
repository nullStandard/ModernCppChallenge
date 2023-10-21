#include <iostream>

template <typename T, size_t R, size_t C>
class Array2D
{
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

    // T** arr;
    T* arr;

public:
    // Array2D() 
    // { 
    //     arr = new int*[R];
    //     for (int i = 0; i < R; i++)
    //         arr[i] = new int[C];
    // }

    // T& operator()(size_t row, size_t column)
    // {
    //     if (row >= R || column >= C)
    //         throw std::out_of_range("wrong demension");
    //     return arr[row][column];
    // }

    
};


int main()
{
    Array2D<int, 2, 3> arr2d;

    arr2d(0, 0) = 5;

    std::cout << arr2d(0, 0) << std::endl;
}