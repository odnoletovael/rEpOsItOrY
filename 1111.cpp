#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
bool is_prime(int c)
{
    for (int i = 2; i <= sqrt(c); ++i)
    {
        if (c % i == 0)
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    vector<int> result;
    int c;
    while (cin >> c && c != 0)
    {
        if (c > 0 && !is_prime(c) && c % 2 != 0 && c % 5 != 0 && c % 3 != 0 && c % 11 != 0)
        {
            result.push_back(c);
        }
    }
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ' ';
    }
    return 0;
}
