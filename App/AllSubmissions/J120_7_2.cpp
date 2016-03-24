#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll int t;
    ll  int n;
    cin>>t;
    while(t--){
            cin>>n;
            if(n%2==0)
                cout<<n;
            else{
                    ll int maxx=n;
                while(1)
                {
                    if( n==1 )
                    {
                        cout<<maxx<<endl;
                        break;
                    }
                    if(n%2==0)
                    {   n=n/2;

                    }
                    else{
                        n=(n*3)+1;
                        if((int)log2(n) == log2(n))
                        {
                        cout<<n<<endl;
                        break;
                    }
                    }
                    if(maxx<n) maxx=n;
                }

            }

    }
    return 0;
}
