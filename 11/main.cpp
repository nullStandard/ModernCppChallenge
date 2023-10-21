// fails at 41. shit like IV, IX, CM etc. should be also treated as a base value.


#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <map>


enum ROMAN : uint16_t
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};

const std::map<uint16_t, std::string> gRomanBinding 
{
    {1,    "I"},
    {5,    "V"},
    {10,   "X"},
    {50,   "L"},
    {100,  "C"},
    {500,  "D"},
    {1000, "M"}
};

const std::vector<ROMAN> gRomanNotation { M, D, C, L, X, V, I };


uint16_t GetNastyRomanSubstractor(int i)
{
    if (std::to_string(gRomanNotation[i]).find("5") != std::string::npos)
    {
        return gRomanNotation[i + 1];
    }
    else 
        return gRomanNotation[i + 2];
}

int main()
{
    std::string romanNumber;
    uint16_t decimal = 0;
    std::cin >> decimal;
    std::cout << "Decimal: " << decimal << " ";

    int i = 0;

    while (decimal)
    {   
        auto division = decimal / gRomanNotation[i];
        if (division == 0)
        {
            uint16_t substr = GetNastyRomanSubstractor(i);
            if (decimal == (gRomanNotation[i] - substr))
            {
                romanNumber.append(gRomanBinding.at(substr));
                romanNumber.append(gRomanBinding.at(gRomanNotation[i]));
                break;
            }
            i++;
        }
        else
        {
            for (int j = 0; j < division; ++j)
                romanNumber.append(gRomanBinding.at(gRomanNotation[i]));
            decimal %= gRomanNotation[i];
        }
    }

    std::cout << "Roman: " << romanNumber << std::endl;
}