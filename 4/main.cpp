#include <iostream>

bool isPrime(int number) // is there some different way using recursion?
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

int CalculateLargestPrime(int userNumber)
{
    for(int i = userNumber - 1; i > 0; --i)
    {
        if(isPrime(i))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int userNumber;
    std::cin >> userNumber;

    std::cout << CalculateLargestPrime(userNumber) << std::endl;
}