#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long int fact(long int n){
    long int i = 1,fact=1;
    while(i<=n){
        fact *= i;
        i++;
    }
    return fact;


}

int main()
{
    int t;
    scanf("%d",&t);
    long int n;
    while(t--){
        scanf("%ld",&n);
        long int temp = n;
        long int count = 0;
        for(long int i=5;i<=100;i++){
            long int x = fact(i);
            long int div = 1;
            long int mc = 0;

            while(x>0){
                 int f = (x/div)%10;

                div*=10;
                //x = x/div;
                if(f==0)
                    mc++;
                else{
                    break;
                }

            }
            if(mc==n){
                printf("%ld\n",i);
                break;
            }
        }
    }
    return 0;
}
