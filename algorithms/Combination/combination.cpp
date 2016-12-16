#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void combination(int n, int k)
{
    string bitmask(k, 1);
    bitmask.resize(n, 0);

    do
    {
        for (int i = 0; i < n; i++)
        {
            if (bitmask[i])
                cout << i << " ";
        }
        cout << endl;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(int argc, char* argv[])
{
    combination(5,3);
}