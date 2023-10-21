#include <iostream>
#include <vector>
#include <iterator>

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

std::vector<int> FindPrimeFactors(int num)
{
    int numCopy = num;
    std::vector<int> primeFactors;
    for (int i = 2; i <= num;) 
    {
        if (numCopy == 1)
            break;

        if (!(numCopy % i)) 
        {
            if (checkPrimeNumber(i))
            {
                primeFactors.push_back(i);
                numCopy /= i;
                continue;
            }
        }
        i++;
    }

    return primeFactors;
}

int main()
{   
    int num = 0;
    std::cin >> num;

    std::vector<int> v = FindPrimeFactors(num);
    std::ostream_iterator<int> os(std::cout, ", ");
    os = v.begin();
}