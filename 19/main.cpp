#include <iostream>
#include <vector>
#include <iterator>
#include <string>

// template <typename C, typename T>
// void AddElement(C& container, T&& value)
// {
//     container.push_back(std::move(value));
// }

// template <typename C, typename T, typename... Args>
// void AddElement(C& container, T&& value, Args&&... args)
// {
//     container.push_back(std::move(value));
//     AddElement(container, args...);
// }


// void AddElement(std::string& container, char value)
// {
//     container.push_back(value);
// }

// template <typename... Args>
// void AddElement(std::string& container, char value, Args... args)
// {
//     container.push_back(value);
//     AddElement(container, args...);
// }

// class A
// {
//     int a;

// public:
//     A(int a) : a(a)
//     {
//         // std::cout << "A(): " << this;
//     }

//     A(const A&)
//     {
//         // std::cout << "A(const A&): " << this;
//     }

//     A(A&&)
//     {
//         // std::cout << "A(A&&): " << this;
//     }

//     ~A()
//     {
//         // std::cout << "~A(): " << this;
//     }

//     friend std::ostream& operator<<(std::ostream& out, const A& other)
//     {
//         out << other.a;

//         return out;
//     }
// };

template <typename C, typename... Args>
void AddElement(C& container, Args&&... args)
{
    (container.push_back(args), ...);
}


template<typename... Args>
void printer(Args&&... args)
{
    (std::cout << ... << args) << '\n';
}


int main()
{
    	printer(1, 2, 3, "abc");

    std::vector<int> v;
    AddElement(v, 5, 4, 3, 2);

    std::ostream_iterator<int> oItV(std::cout, " ");
    std::copy(v.begin(), v.end(), oItV);


    std::string str;
    AddElement(str, '5', '4', '3', '2');

    std::cout << str << std::endl;


    // std::vector<A> vA;

    // A a(5);
    // A b(4);
    // A c(3);
    // A d(2);
    // // AddElement(vA, A(5), A(4), A(3), A(2));
    // AddElement(vA, a, b, c, d);

    // auto it = vA.begin();
    // std::ostream_iterator<A> oItvA(std::cout, " ");
    // std::copy(vA.begin(), vA.end(), oItvA);
}