#include "cstdio"

using namespace std;

int main()
{
long int t;
scanf("%ld",&t);
for(long int i=0;i<t;i++)
{
long long int n;
scanf("%lld",&n);
long long int ans=n*n+n;
ans/=2;
++ans;
printf("%lld\n",ans); 
}
}

