#include <cmath>
#include <iostream>

int main()
{
    float pi = 4 * (4 * atan((double)1 / 5) - atan((double)1 / 239));

    std::cout << pi << std::endl;
}