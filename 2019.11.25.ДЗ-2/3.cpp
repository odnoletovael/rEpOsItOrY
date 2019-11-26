#include <iostream>
#include <vector>

using namespace std;

int main()
{
 int n;
 cin >> n;
 vector<int> a(4 * n + 1, 1);
 for (int i = 2; i <= 4 * n; i++)
 {
 if (a[i] == 1)
 {
 for (int j = i * i; j <= 4 * n; j += i)
 {
 a[j] = 0;
 }
 }
 }
 int cnt = 0;
 for (int i = 2; i <= 4 * n && cnt < n; ++i)
 {
 if (a[i] == 0)
 {
 cout << i << ' ';
 cnt++;
 }
 }
}
