#include "FlatMap.h"
#include <map>
#include <iostream>

#include <boost/container/flat_map.hpp>

int main()
{
    boost::container::flat_map<int, int> a;
    a.insert(std::make_pair(5, 1));
    a.insert(std::make_pair(1, 2));
    a.insert(std::make_pair(3, 4));
    a.insert(std::make_pair(10, 5));
    auto x = a.find(5);
    x->first = 10;
    for (auto c : a)
    {
        std::cout << c.first << " - " << c.second << std::endl;
    }

    std::cout << a[10] << ' ' << a.at(10);

    std::map<int ,float> aaa;
    auto aax = aaa.begin();
    auto aay = aaa.cbegin();
    std::cout << (aax == aay);

    return 0;
}
