#include <algorithm>
#include <vector>
#include <iostream>

template <class BidirIt>
void print(BidirIt first, BidirIt last)
{
    BidirIt it = first;
    while (it != last)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

template <class BidirIt>
bool my_next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;

    while (true)
    {
        BidirIt ii = i;
        if (*--i < *ii)
        {
            BidirIt j = last;
            while (!(*i < *--j));
            //print(first, last);
            std::iter_swap(i, j);
            //print(first, last);
            std::reverse(ii, last);
            //print(first, last);
            //std::cout << std::endl;
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {4,3,2,1,0};
    do
    {
        for (auto val : vec)
            std::cout << val << " ";
        std::cout << std::endl;
    } while (my_next_permutation(vec.begin(), vec.end()));
}