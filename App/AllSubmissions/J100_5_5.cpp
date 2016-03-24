#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t){

        int flag=0;
        int n,k;
        int max=0;
        cin>>n>>k;
        int *a;
        a = new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            if(k%a[i]==0)
            {
                cout<<k<<"\n";
                goto l;
            }
        }
        for(int j=0;j<n;j++){
            int temp = k/a[j];
            int temp1 = temp*a[j];
            if(temp1>max)
                max = temp1;

        }
        cout<<max<<"\n";
        l:
        t--;
    }
    return 0;
}
