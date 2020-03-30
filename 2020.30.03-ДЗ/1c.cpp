#include <iostream>
#include <vector>

using namespace std;

int GeneralizedLevenshteinDistance(string &s1, string &s2, int insert_cost = 1, int delete_cost = 1, int replace_cost = 1)
{
    if (s1.size() > s2.size())
    {
        return GeneralizedLevenshteinDistance(s2, s1, insert_cost, delete_cost, replace_cost);
    }
    int min_size = s1.size();
    int max_size = s2.size();
    vector<int> lev_dist(min_size + 1);
    lev_dist[0] = 0;
    for (int i = 1; i <= min_size; ++i)
    {
        lev_dist[i] = lev_dist[i - 1] + delete_cost;
    }
    for (int j = 1; j <= max_size; ++j)
    {
        int prev = lev_dist[0];
        int tmp = 0;
        lev_dist[0] += insert_cost;
        for (int i = 1; i <= min_size; ++i)
        {
            tmp = lev_dist[i];
            if (s1[i - 1] == s2[j - 1])
            {
                lev_dist[i] = prev;
            }
            else
            {
                lev_dist[i] = min(min(lev_dist[i - 1] + delete_cost, lev_dist[i] + insert_cost), prev + replace_cost);
            }
            prev = tmp;
        }
    }
    return lev_dist[min_size];
}


int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int a, b, c;
    cin >> a >> b >> c;
    cout << GeneralizedLevenshteinDistance(s1, s2, a, b, c);
    return 0;
}

