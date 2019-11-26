#include iostream

#include vector

using namespace std;

int VALUE = 78487894;

int main()

{

int x = 1;

while (true)

{

if ((VALUE - 2020  x) % 2021 == 0)

{

cout « x « ' ' « (VALUE - 2020  x)  2021 « endl;

return 0;

}

x++;

}

}


/*
Перебор эффективен, т.к. мы перебираем только Х, а У вычисляется за О(1)

*/
