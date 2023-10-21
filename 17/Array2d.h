#include <cstddef>
#include <iterator>

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

    T* m_data;
    size_t m_size;

    size_t GetLinearIndex(size_t row, size_t col)
    {
        return row * C + col;
    }

public:
    Array2D()
    {
        m_size = R * C;
        m_data = new int[m_size];
        fill(0);
    }

    Array2D(const std::initializer_list<T>& il)
    {
        m_size = R * C;
        if (il.size() != m_size)
            throw std::out_of_range("sizes do not match"); 

        m_data = new int[m_size];

        for(auto i = il.begin(); i < il.end(); ++i)
            m_data[std::distance(il.begin(), i)] = *i;
    }

    Array2D(const Array2D& otherArray2d)
    { 
        m_size = otherArray2d.m_size;
        m_data = new T[m_size];
        std::copy(otherArray2d.begin(), otherArray2d.end(), this->begin());
    }

    Array2D(Array2D&& otherArray2d) : Array2D()
    { 
        swap(otherArray2d);
    }


    T& operator()(size_t row, size_t col)
    {
        if (row >= R || col >= C)
            throw std::out_of_range("wrong demension"); 

        size_t linIndex = GetLinearIndex(row, col);
        return m_data[linIndex];
    }

    size_t GetRows()
    {
        return R;
    }

    size_t GetColumns()
    {
        return C;
    }

    void fill(T value)
    {
        std::fill(this->begin(), this->end(), value);
    }

    void swap(Array2D& otherArray2d)
    {
        std::swap(this->m_data, otherArray2d.m_data);
        std::swap(this->m_size, otherArray2d.m_size);
    }

    Array2D& operator=(const Array2D& otherArray2d)
    {
        if (m_data)
            delete[] m_data;
        m_size = otherArray2d.m_size;
        m_data = new T[m_size];
        std::copy(otherArray2d.begin(), otherArray2d.end(), this->begin());

        return *this;
    }

    Array2D& operator=(Array2D&& otherArray2d)
    {
        if (m_data)
            delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        swap(otherArray2d);

        return *this;
    }

    Iterator begin() const
    {
        return Iterator(m_data);
    }

    Iterator end() const
    {
        return Iterator(m_data + m_size);
    }

    friend std::ostream& operator<<(std::ostream& out, Array2D & arr2d)
    {
        for (int i = 0; i < arr2d.GetRows(); ++i)
        {
            for (int j = 0; j < arr2d.GetColumns(); ++j)
                out << arr2d(i, j) << " ";
            out << std::endl;
        }

        return out;
    }
};