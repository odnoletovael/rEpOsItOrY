#include <iostream>
#include <vector>

using namespace std;

int main()
{
 int n;
 cin >> n;
 vector<char> a(n);
 for (int i = 0; i < n; ++i)
 {
 cin >> a[i];
 }
 while (true)
 {
 int ind = -1;
 for (int i = 0; i < n - 1; ++i)
 {
 if (a[i] < a[i + 1])
 {
 ind = i;
 }
 }
 if (ind == -1)
 {
 break;
 }
 int l = ind + 1;
 for (int i = ind + 1; i < n; ++i)
 {
 if (a[ind] < a[i])
 {
 l = i;
 }
 }
 swap(a[ind], a[l]);
 for (int i = ind + 1; i <= (n + ind) / 2; ++i)
 {
 swap(a[i], a[n - i + ind]);
 }
 for (int i = 0; i < n; ++i)
 {
 cout << a[i];
 }
 cout << endl;
 }
}
