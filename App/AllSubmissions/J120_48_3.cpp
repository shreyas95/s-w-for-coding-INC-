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
            if(n==1) printf("%d\n",2);
            else
            printf("%d\n",(n*(n+1)/2)+1);


    }
    return 0;
}
