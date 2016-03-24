#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll int fact(ll int n)
{
    ll int i=5;
    ll int c=0;
    while(i<=n)
    {
        c+=n/i;
        i=pow(i,5);
//        cout<<"  "<<n<<" "<<i<<" "<<c<<endl;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll int n;
    cin>>t;
    while(t--){
            cin>>n;
            ll int tmp=1;
            ll int newn=5;
            while(1)
            {
                tmp=fact(newn);
//                cout<<"count"<<tmp<<" "<<newn;;

                if(tmp==n)
                {
                    cout<<newn<<endl;
                    break;
                }
                newn+=5;

            }

    }
    return 0;
}
