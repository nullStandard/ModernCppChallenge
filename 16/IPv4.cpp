#include "IPv4.h"

IPv4::IPv4(uint32_t ip) 
{
    SetIpFromRaw(ip);
}

IPv4& IPv4::operator=(uint32_t ip)
{
    SetIpFromRaw(ip);
    return *this;
}

IPv4& IPv4::operator++(int)
{
    SetIpFromRaw(this->GetRaw() + 1);
    return *this;
}

IPv4& IPv4::operator--(int)
{
    SetIpFromRaw(this->GetRaw() - 1);
    return *this;
}

bool operator<(const IPv4& ipLeft, const IPv4& ipRight)
{
    return ipLeft.GetRaw() < ipRight.GetRaw();
}

bool operator>(const IPv4& ipLeft, const IPv4& ipRight)
{
    // return ipLeft.GetRaw() > ipRight.GetRaw();
    return ipRight < ipLeft;
}

std::istream& operator>>(std::istream& in, IPv4& IPv4)
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

std::ostream& operator<< (std::ostream& out, const IPv4& IPv4)
{
    std::ostream_iterator<int> outIt(out, ".");
    std::copy(IPv4.m_ip.cbegin(), IPv4.m_ip.cend(), outIt);

    std::cout << "NEW CHANGES YOUHOOOE!" << std::endl;
    return out;
}

uint32_t IPv4::GetRaw() const
{
    uint32_t raw = 0x0;
    int bias = 24;
    for (const uint8_t i : m_ip)
    {
        raw |= ((uint32_t)i << bias);
        bias -= 8;
    }

    return raw;
}

void IPv4::SetIpFromRaw(uint32_t raw)
{
    uint32_t mask = 0xff;
    int bias = 24;
    for (uint8_t& i : m_ip)
    {
        i = (raw >> bias) & mask;
        bias -= 8;
    }
}

std::vector<IPv4> IPv4::ListIPAddressesBetween(const IPv4& ip1, const IPv4& ip2)
{
    auto minRaw = std::minmax(ip1.GetRaw(), ip2.GetRaw());
    std::vector<IPv4> ipSet;

    for (uint32_t i = minRaw.first + 1; i < minRaw.second; ++i)
    {
        ipSet.push_back(IPv4(i));
    }

    return ipSet;
}