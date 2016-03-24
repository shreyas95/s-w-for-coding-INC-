#include <iostream>
#include <bits/stdc++.h>
using namespace std;
inline int check(int num)
{
int numz[10] = {0};
int swap,i ;
for (swap = num; swap != 0; swap /= 10)
numz[swap % 10]++;
for (i = 2 ; i <= 6 ; i++)
{
for (swap = num * i; swap != 0; swap /= 10)
if (! (numz[swap % 10]))
// pure luck
return 0;
}
return 1;
}
int main()
{
int i;
for (i = 10 ;; i++)
if (check(i))
break;
return printf("%d\n" , i);
} 