#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

template<class T, typename Comparator> T findOrderSize(const std::vector<T> &vec)
{
    Comparator comp;

    for(size_t i = 1; i < vec.size(); ++i)
    {
        if (comp(vec[i-1],vec[i]))
        {
            return i;
        }
    }
    return vec.size();
}

template<class T> std::vector<int> swapSort(std::vector<T> &vec)
{
    std::vector<int> changeList;
    int lastOrderSize = 0;

    while (!is_sorted(vec.begin(), vec.end()))
    {
        int orderSize = std::max(findOrderSize<T, std::greater<T>>(vec), findOrderSize<T, std::less<T>>(vec));

        if(lastOrderSize == orderSize)
        {
            ++lastOrderSize;
        }
        else
        {
            lastOrderSize = orderSize;
        }

        changeList.push_back(lastOrderSize);
        std::reverse(vec.begin(), vec.begin() + lastOrderSize);
    }

    return changeList;
}

int main()
{
    std::vector<int> vec;
    for(size_t i = 0; i < 20; ++i)
    {
        vec.push_back(rand() % 20);
    }

    auto ret = swapSort(vec);

    for(const int val: vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    for(const int prvok: ret)
    {
        std::cout << prvok << std::endl;
    }

    std::cout << ret.size() << std::endl;

    return 0;
}
