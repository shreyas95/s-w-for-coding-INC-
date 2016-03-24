#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(long long int i=0;i<10000000000000000;i++){
        vector<long long int> v;
        long long int j = i;
        long long int twoi = i*2;
        long long int threei = i*3;
        long long int fouri = i*4;
        long long int fivei = i*5;
        long long int sixi= i*6;
        long long int div = 1;
        while(j>0){
            j = (j/div)%10;
            v.push_back(j);
            div = div*10;
        }
        for()

    }
    return 0;
}
