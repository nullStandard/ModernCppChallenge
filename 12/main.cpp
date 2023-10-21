#include <iostream>
#include <vector>
#include <algorithm>

size_t GetCollatzSequenceLength(size_t num)
{
    if (num == 1)
        return 1;
    if (num % 2 == 0)
        num /= 2;
    else
        num = 3 * num + 1;

    return 1 + GetCollatzSequenceLength(num);
}


int main()
{
    std::vector<size_t> length(1'000'000); 
    for (int i = 1; i <= 1'000'000; ++i)
        length[i - 1] = GetCollatzSequenceLength(i);
    
    auto max_element = std::max_element(length.begin(), length.end());
    std::cout << "element " << std::distance(length.begin(), max_element) << " has length " << *max_element << std::endl;
}