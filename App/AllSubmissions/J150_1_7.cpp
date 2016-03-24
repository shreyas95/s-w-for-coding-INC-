#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,m,t;
    cout<<"\nHow many no. you want to test=";
    cin>>t;
    if(t<=100 || t>=1)
    {
        for(int i=0;i<t;i++)
        {
             cout<<"\nEnter no.=";
            cin>>n;
            if(n>=1 || n<=pow(10,16) )
            {
                cout<<"\nAns is"<<5*n;
            }
            else
            {

                cout<<"\nEnter valid no.=";
                break;
            }
        }

    }
    else
    {
        cout<<"Enter valid test no.";
    }
    return 0;
}
