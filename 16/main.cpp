#include <iostream>

#include "IPv4.h"


int main(int argc, char** argv)
{
    IPv4 IP1;
    IPv4 IP2;

    std::cin >> IP1;
    std::cin >> IP2;

    std::cout << IP1 << std::endl;
    std::cout << IP2 << std::endl;

    IPv4 IP = IP1;
    while(IP < IP2)
    {
        std::cout << IP << std::endl;
        IP++;
    }
}