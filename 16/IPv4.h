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
    using ip_t = std::array<uint8_t, 4>;

    ip_t m_ip;

public:
    IPv4(ip_t ip) : m_ip(ip) { }
    explicit IPv4(uint32_t ip);

    IPv4() : m_ip({0, 0, 0, 0}) { }
    IPv4(const IPv4&) = default;

    IPv4& operator=(const IPv4&) = default;
    IPv4& operator=(uint32_t ip);

    IPv4& operator++(int);
    IPv4& operator--(int);

    friend bool operator<(const IPv4& ipLeft, const IPv4& ipRight);
    friend bool operator>(const IPv4& ipLeft, const IPv4& ipRight);

    friend std::istream& operator>>(std::istream& in, IPv4& IPv4);
    friend std::ostream& operator<< (std::ostream& out, const IPv4& IPv4);

    uint32_t GetRaw() const;
    void SetIpFromRaw(uint32_t raw);

    static std::vector<IPv4> ListIPAddressesBetween(const IPv4& ip1, const IPv4& ip2);
};