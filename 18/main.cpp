#include <algorithm>
#include <iostream>

template <typename C, typename T>
T minimum(C cmp, T first)
{
    return first;
}


template <typename C, typename T, typename... Args>
T minimum(C cmp, T first, Args... args)
{
    // return std::min(first, minimum(args...));
    auto min = minimum(cmp, args...);
    return cmp(first, min) ? first : min;
}


// template <typename C, typename T>
// T minimum(C cmp, T const a, T const b) { return cmp(a, b) ? a : b; }


// template <typename C, typename T1, typename... T>
// T1 minimum(C cmp, T1 a, T... args)
// {
//     return minimum(cmp, a, minimum(cmp, args...));
// }

int main()
{
    std::cout << minimum(std::less<>(), 10, 9, 2, -5, 899, 333, 2, 0, 15) << std::endl;
}
