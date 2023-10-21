#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <cstdint>


bool CheckISBN(std::string& sISBN)
{
    std::vector<int> dodanok(10);
    std::iota(dodanok.rbegin(), dodanok.rend(), 1);

    std::generate(dodanok.begin(), dodanok.end(), [&, n = 0]() mutable {
        int ch;
        std::stringstream ss;
        
        if(sISBN[n] == 'X')
            ch = 10;
        else
        {
            ss << sISBN[n];
            ss >> ch;
        }

        static auto it = dodanok.begin();

        int mult = 0;
        if (it != dodanok.end())
        {
	        mult = *it * ch;
            ++it;
        }

        n++;
        return mult;
    });

    int sum = std::accumulate(dodanok.rbegin(), dodanok.rend(), static_cast<int>(0));

    return (sum % 11) == 0;
}

int main()
{
    std::string sISBN;
    std::cin >> sISBN;
        
    std::cout << CheckISBN(sISBN);
}