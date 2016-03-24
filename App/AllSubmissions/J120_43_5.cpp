#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll int t,k,n;
    vector <int> arr;
    cin>>t;
    while(t--){
        cin>>n>>k;
        arr.clear();
        ll int temp=0;
        int flag2=0;
        ll int val=0;
        ll int ii=0;
        ll int arbi=0;
        ll int sum=0;
        while(n--)
        {
            cin>>temp;
            arr.push_back(temp);
            if(k%temp==0 )
            {
                      flag2=1;

            }
        }
        if(flag2==1)
        {

        cout<<k;
            continue;
        }
        while(1)
        {

            int maxx = -1;
            int index=0;int flag=0;;
            for(int i=0;i<arr.size();i++)
            {
                if(maxx<arr[i] && arr[i] <=k-sum)
                {maxx=arr[i];
                index=i;
                cout<<"MAXX"<<maxx<<" "<<index<<endl;
                }
            }
            flag=0;
            for(int i=0;i<arr.size();i++)
            {


                if(arr[i]<=k && arr[i]>0)
            {


                    flag=1;
                    break;
            }
            }
            sum+=maxx;
if(flag==1)
                 {

                cout<<sum;
                break;

               }

               if(sum==k)
               {

                cout<<sum;
                break;

               }
               if(sum>k)
               {
                   cout<<sum-maxx;
                   break;
               }

//cout<<sum;
//int z;
//cin>>z;

            }
            }



//        cout<<val<<endl;

    return 0;
}
