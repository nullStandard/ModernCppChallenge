#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
class Wrapper
{
    T m_sysHandle;

public:
    Wrapper() = default;
    Wrapper(const char* filename, std::ios_base::openmode mode = std::ios_base::out | 
                                                                 std::ios_base::in  )
    {
        m_sysHandle.open(filename, mode);
    }

    Wrapper(const Wrapper&) = delete;
    Wrapper(Wrapper&& otherWrapper) = default;

    Wrapper& operator=(const Wrapper&) = delete;
    Wrapper& operator=(Wrapper&& otherWrapper) = default;

    bool IsGood()
    {
        return m_sysHandle.good();
    }

    void Open(const char* filename, std::ios_base::openmode mode = std::ios_base::out | 
                                                                   std::ios_base::in  )
    {
        m_sysHandle.open(filename, mode);
    }

    void Close()
    {
        m_sysHandle.close();
    }

    Wrapper& operator<<(int a)
    {
        m_sysHandle << a;
        return *this;
    } 

    ~Wrapper()
    {
        m_sysHandle.close();
    }
};

int main()
{
    Wrapper<std::fstream> file("Hello.txt", std::ios_base::out | std::ios_base::trunc);
    file << 5;

    std::cout << std::boolalpha << file.IsGood() << std::endl;

    Wrapper<std::fstream> fileMoved(std::move(file));

    std::cout << std::boolalpha << file.IsGood() << std::endl;

    file << 10;

    std::cout << std::boolalpha << file.IsGood() << std::endl;

    fileMoved << 20;
}