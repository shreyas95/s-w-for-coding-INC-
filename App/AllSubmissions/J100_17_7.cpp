#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int fact(long long int n){
    long long int i = 1,fact=1;
    while(i<=n){
        fact *= i;
        i++;
    }
    return fact;


}

int main()
{
    int t;
    cin>>t;
    long long int n;
    int i = 15;
    while(t--){
        cin>>n;
        /*long long int temp = n;
        long long int count = 0;
        for(long long int i=5;i<=100;i++){
            long long int x = fact(i);
            long long int div = 1;
            long long int mc = 0;

            while(x>0){
                 int f = (x/div)%10;

                div*=10;
                if(f==0)
                    mc++;
                else{
                    break;
                }

            }
            if(mc==n){
                cout<<i<<"\n";
                break;
            }
        }*/
        cout<<i<<"\n";
        i+=5;
    }
    return 0;
}
