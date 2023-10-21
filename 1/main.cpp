#include <iostream>

int main()
{
    size_t count = 0;
    int a;
    std::cin >> a;

    for(int i = 1; i <= a; ++i) 
        if(i % 3 == 0 || i % 5 == 0)
        {
            count += i;
            std::cout << i << "\n";
            }
            
    
    std::cout << "Sum is " << count << std::endl;
    return 0;
}