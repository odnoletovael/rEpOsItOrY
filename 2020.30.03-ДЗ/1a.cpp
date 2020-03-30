#include <iostream>

using namespace std;

int hamming(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] != s2[i])
        {
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << hamming(s1, s2);
    return 0;
}
