#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <cinttypes>
#define int __int128
using namespace std;
constexpr int MOD = 1e6;
int gcdex(int a, int b, int& x, int& y) {
if (a == 0) {
 x = 0;
 y = 1;
 return b;
    }
 int x1, y1; 
 int d = gcdex(b % a, a, x1, y1);
 x = y1 - (b / a) * x1;
 y = x1;
 return d;
} 
int inverse(int a, int m) {
int x, y;
gcdex(a, m, x, y);
x = (x % m + m) % m;
return x;
}
 
int binPowMod(int a, int k, int n) {
 int res = 1;
 while (k) {
if (k & 1) {
res = (a % n) * (res % n) % n;
}
 a = (a % n) * (a % n) % n;
 k >>= 1;
 }
 return res % n;
}
auto main() -> signed {
srand(time(0)); 
int p = 1e3+13, q = 1e3+17; // взаимнопростые числа
int n = p * q;
int k = (p - 1) * (q - 1);
int e = 127; // простое число, которое точно взаимнопростое с k
int d = inverse(e, k);
cout << "d:\t\t" << d << '\n';
int message = rand() % p*q;
cout << "message:\t" << message;
int c = binPowMod(message, e, n);
cout << "\nencoded:\t" << c;
cout << "\ndecoded:\t" << binPowMod(c, d, n);
}
