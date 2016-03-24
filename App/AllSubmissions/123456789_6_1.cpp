#include<iostream>
//#include<time.h>

using namespace std;

int josephus(int n,int k){
 if (n ==1)
     return 1;
   else return ((josephus(n-1,k)+k-1) % n)+1;
}
int main()
{
//clock_t s=clock();
int t,n,k;
cin>>t;
while(t--){
cin>>n>>k;
cout<<josephus(n,k)<<"\n";
}
//cout<<"ertyu"<<clock()-s;
return 0;
}
