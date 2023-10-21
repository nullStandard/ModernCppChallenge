#include <array>
#include <cstdint>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <limits>

class IPv4
{
    using ip_t = std::array<uint32_t, 4>;

    ip_t m_ip;

public:
    IPv4(ip_t ip) : m_ip(ip) { }
    explicit IPv4(uint32_t ip) 
    {
        uint32_t mask = 0xff;
        int bias = 24;
        for (uint32_t& i : m_ip)
        {
            i = (ip >> bias) & mask;
            bias -= 8;
        }

        // std::generate(m_ip.rbegin(), m_ip.rend(), [&]() mutable {
        //     uint32_t mask = 0b00000000'00000000'00000000'11111111;

        //     static int bias = 0;

        //     ip >>= bias;
            
        //     bias += 8;


        //     return ip & mask;
        // });
    }

    IPv4() : m_ip({0, 0, 0, 0}) { }

    friend std::istream& operator>> (std::istream& in, IPv4& IPv4)
    {
        std::string strFromCin;
        in >> strFromCin;

        char str[16];
        strcpy(str, strFromCin.c_str());

        char* strtokIndx = strtok(str, ".");
        std::generate(IPv4.m_ip.begin(), IPv4.m_ip.end(), [&]() mutable {
            char* fillStr = strtokIndx;
            strtokIndx = strtok(NULL, ".");
            return (int)atoi(fillStr);
        });

        return in;
    }

    friend std::ostream& operator<< (std::ostream& out, const IPv4& IPv4)
    {
        std::ostream_iterator<int> outIt(out, ".");
        std::copy(IPv4.m_ip.cbegin(), IPv4.m_ip.cend(), outIt);

        return out;
    }
};


int main(int argc, char** argv)
{
    IPv4 IP (0xff'ff'ff'ff);
    // std::cin >> IP;

    std::cout << IP << std::endl;
}