#include <iostream>
#define ll long long
#include<math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll int t;
    ll  int n;
    cin>>t;
    while(t--){
            cin>>n;
                ll int maxx=n;
                while(1)
                {
                    if( n==1 || n==2 || n==4 || n==8 || n==16 ||n==32 )
                    {
                        cout<<maxx<<endl;
                        break;
                    }
                    if(n%2==0)
                    {
                        n=n/2;
                    }
                    else{
                        n=(n*3)+1;
                    }
                    if(maxx<n) maxx=n;
                }



    }
    return 0;
}
