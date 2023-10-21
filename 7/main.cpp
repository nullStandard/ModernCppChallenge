#include <vector>
#include <set>
#include <numeric>
#include <iostream>
#include <algorithm>

const int MAX_BOUND = 1'000'000;


bool checkPrimeNumber(int n) {
    bool isPrime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

std::set<int> GetDilnyks(int number)
{
    std::set<int> dilnyks;
    if (checkPrimeNumber(number))
    {
        dilnyks.insert(1);
        return dilnyks;
    }
    for (int i = 1; i <= number / 2; ++i)
    {
        if (number % i == 0)
            dilnyks.insert(i);
    }

    return dilnyks;
}

int GetSumOfDilnyks(int number)
{   
    auto dilnyks = GetDilnyks(number);
    return std::accumulate(dilnyks.begin(), dilnyks.end(), 0);
}

bool CheckIfLessThanMillion(int number)
{
    return number < MAX_BOUND;
}


int main()
{
    std::cout << GetSumOfDilnyks(132862) << std::flush;
    std::vector<int> oneToMillion(MAX_BOUND, -1);

    int index = 0;
    auto counter = oneToMillion.begin();
    while (counter != oneToMillion.end())
    {
        index = std::distance(oneToMillion.begin(), counter);

        int sum1 = 0;
        int sum2 = 0;

        while (index < MAX_BOUND)
        {
            if (!oneToMillion[index])
                break;
            sum1 = GetSumOfDilnyks(index + 1);
            if (sum1 > MAX_BOUND)
                break;
            sum2 = GetSumOfDilnyks(sum1);
            if ((index + 1) != sum2)
            {
                oneToMillion[index] = 0;
                index = sum2 - 1;
            }
            else
            {    
                oneToMillion[index] = 0;
                oneToMillion[sum1 - 1] = 0;
                if ((index + 1) != sum1)
                    printf("(%d, %d)\n", index + 1, sum1);
                break;
            }
        }  
    counter = std::find(counter, oneToMillion.end(), -1);
    }
}