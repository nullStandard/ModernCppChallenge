#include <iostream>
#include <cstdint>
#include <bitset>

using BYTE = uint8_t;

std::bitset<5> GetGrayFromBin(std::bitset<5> bin)
{
    return bin ^ (bin >> 1);
}

std::bitset<5> GetBinFromGray(std::bitset<5> gray)
{
    std::bitset<5> bin;
    bin[4] = gray[4];

    for (int i = 3; i >= 0; --i)
        bin[i] = gray[i] ^ bin[i + 1];

    return bin;
}


int main()
{
    for (std::bitset<5> i = 0b0; ; i = i.to_ulong() + 1)
    {
        std::bitset<5> gray = GetGrayFromBin(i);
        std::cout << "binary: " << i << "\tGray: " << gray << "\tDecoded Gray: " << GetBinFromGray(gray) << std::endl; 

        if (i.to_ulong() == 0b11111)
            break;
    }  
}