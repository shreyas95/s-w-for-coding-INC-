#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    double t,n,temp,a[5];
    cin>>t;
    //if(t>=1 && t<=100000)
    //{
        for(int i=0;i<t;i++)
        {
            cin>>n;
            if(n<100000 && n>1)
            {
                 temp=n;
                n=1;
                while(temp!=1)
                {
                    if(int (temp)%2==0)
                    {

                       temp=temp/2;
                    }
                    else
                    {
                        temp=(temp*3)+1;
                    }
                    if(n<temp)
                    {
                        n=temp;
                    }
                }
                cout<<n<<"\n";
            }
            else{
                cout<<n<<"\n";
            }

        }




    //}

}