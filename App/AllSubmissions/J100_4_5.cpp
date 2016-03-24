#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t){

        int flag=0;
        int n,k;
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
        l:
        t--;
    }
    return 0;
}
