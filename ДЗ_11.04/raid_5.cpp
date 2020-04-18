#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main() {
int a = 10;
while (a--) {
srand(time(nullptr));
 
int k, n;
k = rand() % 1000 + 2;
m = rand() % 1000 + 2;
 
vector<vector<int>> buffer(k, vector<int>(n));
 for (int i = 0; i < k; i++) {
 for (int j = 0; j < n; j++) {
 buffer[i][j] = rand() % 2000000009;
    }
  }
 vector<int> control(n);
for (int i = 0; i < n; i++) {
for (int j = 0; j < k; j++) {
 control[i] ^= buffer[j][i];
 }
}
 int destroy = rand() % k;
 vector<int> test = buffer[destroy];
 buffer[destroy] = control;
 for (int i = 0; i < n; i++)
 {
for (int j = 0; j < k; j++)
 {
if (j == destroy) continue;
buffer[destroy][i] ^= buffer[j][i];
 }
 }
 if (buffer[destroy] == test) {
 cout << "YES" << endl;
 } else {
 cout << "NO" << endl;
 return 0;
  }
 }
}
