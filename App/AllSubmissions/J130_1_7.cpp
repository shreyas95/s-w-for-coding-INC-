#include <iostream>

using namespace std;

int main()
{
    int t,n,j,i,h=1;
    long int mul=1;
    cin>>t;
    cout<<"\n";

for(j=0;j<t;j++)
{


        cin>>n;
        cout<<"\n";
        for(int k=0;k<n;k++)
        {
            h=h*10;
        }

       for(i=1;i<500;i++)
    {

          if(mul%h==0)
          {
            cout<<i-1<<endl;
            break;
          }

        mul=mul*i;

    }


}
}
