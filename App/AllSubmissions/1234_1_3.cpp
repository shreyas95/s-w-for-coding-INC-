#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int x)
{
    int div = 5;
    int ans=0;
    while(x/div >0)
    {
        ans += x/div;
        div = div*5;
    }
    return ans;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=1;
        while(1)
        {
            if(func(x)==n)
                break;
            x++;
        }
        cout<<x<<endl;
    }
    return 0;
}
