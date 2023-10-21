#include <string>
#include <vector>

#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <cmath>

int main()
{
    std::vector<uint16_t> armstrong;  
    for (int i = 100; i <= 999; ++i)
    {
        std::string str = std::to_string(i);
        const char* rawStr = str.c_str();
        size_t digitSum = 0;
        for (int i = 0; i < 3; ++i)
        {
            int ch = rawStr[i];
            digitSum += std::pow(std::atoi((char*)(&ch)), 3);
        }
        if (digitSum == i)
            armstrong.push_back(i);
    }

    std::cout << "Armstrong nums: ";
    for (auto i: armstrong)
        std::cout << i << " ";
    std::cout << std::endl;
}