#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum =0;
        int le = 1;
        int k,newp;
        for(int i=2;i<=n;i++){
            newp = le+1;
            sum += newp;
            le++;
        }
        cout<<sum+2<<"\n";
    }
    return 0;
}
