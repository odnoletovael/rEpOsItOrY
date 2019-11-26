#include <iostream>

#include <vector>

using namespace std;

void find_palindrome(int n, int i, vector<int> &a)

{

if (n % 2 == 0)

{

if (i >= n / 2)

{

return;

}

if (i == n / 2 - 1)

{

for (int j = 0; j < 10; ++j)

{

a[i] = j;

a[i + 1] = j;

for (int g = 0; g < n; ++g)

{

cout « a[g];

}

cout « endl;

}

}

else

{

for (int j = 0; j < 10; ++j)

{

a[i] = j;

a[n - i - 1] = j;

find_palindrome(n, i + 1, a);

}

}

}

else

{

if (i > n / 2)

{

return;

}

if (i == n / 2)

{

for (int j = 0; j < 10; ++j)

{

a[i] = j;

for (int g = 0; g < n; ++g)

{

cout « a[g];

}

cout « endl;

}

}

else

{

for (int j = 0; j < 10; ++j)

{

a[i] = j;

a[n - i - 1] = j;

find_palindrome(n, i + 1, a);

}

}

}

}

int main()

{

int n;

cin » n;

vector<int> a(n);

for (int i = 1; i < 10; ++i)

{

a[0] = i;

a[n - 1] = i;

find_palindrome(n, 1, a);

}

}

/*

Данный перебор является эффективным, т.к. каждый шаг рекурсии мы находим новый палиндром(новый, т.к. мы постоянно берем разные цифры для рекурсии),

а т.к. вывести все палиндромы менее, чем за их количество нельзя, то этот алгоритм эффективен.

*/
