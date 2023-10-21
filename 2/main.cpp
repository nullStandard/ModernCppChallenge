// not so good approach, the best one - Euclid's algo:
// The method introduced by Euclid for computing 
// greatest common divisors is based on the fact that, 
// given two positive integers a and b such that a > b, 
// the common divisors of a and b are the same 
// as the common divisors of a – b and b.
//
// - too slow when a >> b (or vice versa)
//
// A more efficient method is the Euclidean algorithm, 
// a variant in which the difference of the two numbers 
// a and b is replaced by the remainder of the Euclidean 
// division (also called division with remainder) of a by b.




#include <set>
#include <iostream>

void PrintDivisors(const std::set<int>& divisors)
{
    for(const auto i : divisors)
        std::cout << i << " ";
    std::cout << std::endl;
}

int GetMaxDivisorForNum(int num)
{
    std::set<int> divisors;
    for(int i = 1; i <= num; ++i)
    {
        if(num % i == 0)
        {
            divisors.insert(i);
        }
    }
    PrintDivisors(divisors);
    return *divisors.rbegin();
}

int GetMaxCommonDivisor(int a, int b)
{
    int maxDivForA = GetMaxDivisorForNum(a);
    int maxDivForB = GetMaxDivisorForNum(b);
    return std::min(maxDivForA, maxDivForB);
}


int EuclidAlgo(int a, int b)
{
    if(!b)
        return a;
    
    return EuclidAlgo(b, a % b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    std::cout << GetMaxCommonDivisor(a, b) << std::endl;
    std::cout << EuclidAlgo(a, b) << std::endl;

    return 0;
}