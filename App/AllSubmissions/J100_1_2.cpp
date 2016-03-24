#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*#define getchar_unlocked gc
using namespace std;
void scanint(int &x)
{
    char c=getchar_unlocked();
    x=0;
    while(c<'0' || c>'9')
    {
        c = gc();
    }
    while(c>='0' && c<='9')
    {
        x= x<<1 + x<<3 + c -48;
        c=gc();
    }

}*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int temp,max=0;
        scanf("%d",&temp);
        max=temp;
        while(temp!=1){
            if(temp%2==0)
            {
                temp= temp>>1;
                if(temp>max)
                    max=temp;
            }
            else{
                temp= (temp+ (temp<<1)) +1;
                if(temp>max)
                    max=temp;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
