#include <iostream>

using namespace std;

int main()
{
    int t,j,n ;

    cin>>t;
    cout<<"\n";

for(j=0;j<t;j++)
{
cin>>n;
while(1)
{
    if(n%4==0 || n==1 || n==2)
        break;
    else
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=(n*3)+1;
        }
    }

}
cout<<n<<"\n";


}
}
