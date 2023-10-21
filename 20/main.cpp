#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <array>

template<typename... Args>
void printer(Args&&... args)
{
    (std::cout << ... << args) << '\n';
}

template <typename C, typename... Args>
bool contains_any(const C& container, Args... args)
{
    return ((std::find(container.begin(), container.end(), args) != container.end()) || ...);
}

template <typename C, typename... Args>
bool contains_all(const C& container, Args... args)
{
    return ((std::find(container.begin(), container.end(), args) != container.end()) && ...);
}

template <typename C, typename... Args>
bool contains_none(const C& container, Args... args)
{
    return !contains_any(container, args...);
}

int main()
{
    std::vector<int> v{ {1, 2, 3, 4, 5, 6} };
    assert(contains_any(v, 0, 4, 10, 30));
    assert(contains_all(v, 1, 3, 5, 6));

    std::array<int, 6> a{ {1, 2, 3, 4, 5, 6} };
    assert(("there something is present!", contains_none(a, 0, 4, 10, 30)));

}

// template<class C, class T>
// bool contains(C const & c, T const & value)
// {
// return std::end(c) != std::find(std::begin(c), std::end(c), value);
// }

// template<class C, class... T>
// bool contains_any(C const & c, T &&... value)
// {
// return (... || contains(c, value));
// }

// template<class C, class... T>
// bool contains_all(C const & c, T &&... value)
// {
// return (... && contains(c, value));
// }

// template<class C, class... T>
// bool contains_none(C const & c, T &&... value)
// {
// return !contains_any(c, std::forward<T>(value)...);
// }