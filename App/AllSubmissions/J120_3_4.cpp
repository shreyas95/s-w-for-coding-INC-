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
        cout<<n%(b-1)<<endl;    }
    return 0;
}
