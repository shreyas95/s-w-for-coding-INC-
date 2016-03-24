#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll int t,b,n;
    cin>>t;
    while(t--){
        cin>>b>>n;
        ll int temp=0;
        ll int val=0;
        ll int ii=0;
        while(n){
            temp=n%10;
            val+=temp*ceil(pow(b,ii));
            cout<<"hi "<<val<<endl;
            n/=10;
            ii++;
        }
//        cout<<val<<endl;
        cout<<(ll int)val%(b-1)<<endl;    }
    return 0;
}
