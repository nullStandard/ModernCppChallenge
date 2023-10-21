#include <iostream>
#include <vector>

bool IsPrime(int number) // is there some different implementation using recursion?
{
    if(number == 1)
        return false;
    if(number == 2)
        return true;
    
    for(int i = 2; i < number; i++)
    {
        if(!(number % i))
            return false;
    }
    return true;
}

void PrintSexyPrimes(const std::vector<std::pair<int, int>>& sexyPairs)
{
    for(const auto& p: sexyPairs)
        std::cout << "(" << p.first << ", " << p.second << "), " << std::flush;
    std::cout << std::endl;
}

int main()
{
    int limit;
    std::cin >> limit;

    std::vector<std::pair<int, int>> sexyPairs;

    for(int i = 2; i <= limit - 6; ++i)
    {
        if(IsPrime(i))
        {
            if(IsPrime(i + 6))
            {
                sexyPairs.push_back({i, i + 6});
            }
        }
    }

    PrintSexyPrimes(sexyPairs);
}