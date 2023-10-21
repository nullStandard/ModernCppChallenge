#include <iostream>
#include <vector>
#include <numeric>
#include <optional>

std::optional<std::vector<int>> GetAbundancesIfExist(int num)
{
    std::vector<int> abundances;
    for(int i = 1; i < num; ++i)
    {
        if(num % i == 0)
        {
            abundances.push_back(i);
        }
    }
    if (std::accumulate(abundances.begin(), abundances.end(), 0) > num)
        return abundances;
    else
        return std::nullopt;
}

void PrintAbundances(int num, const std::vector<int>& abundances)
{
    std::cout << num << ": ";
    for(const auto& a: abundances)
        std::cout << a << " " << std::flush;
    std::cout << std::endl;
}


int main()
{
    int number;
    std::cin >> number;

    for(int i = 1; i <= number; i++)
    {
        auto abundances = GetAbundancesIfExist(i);
        if(abundances.has_value())
            PrintAbundances(i, abundances.value());
    }
}