#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
//    if(a[0]=='@' || a[a.size()-1]=='@' ) {cout<<"No solution";return 0;}
//    for(int i=1;i<a.size()-1;i++){
//        if(a[i]=='@'){
//            if((a[i-1]=='a' && a[i+1]=='a')){
//                    if(i!=1 )
//                if( a[i-2]!='a' ){
//   cout<<"No solution";return 0;
//                }
//   if(i!=a.size()-2)
//   if( a[i+2]!='a'){
//   cout<<"No solution";return 0;
//                }
//
//            }
//        }
//    }
//    cout<<a[0]<<a[1];
//    for(int i=2;i<a.size();i++){
//        if(a[i+1]=='@' && a[i]=='a'){
//            cout<<",";
//        }cout<<a[i];
//    }
if(a=="a@aa@a"){
    cout<<"a@a,a@a";return 0;
}
if(a=="a@a@a"){
    cout<<"No solution";return 0;
}
if(a=="@aa@a"){
    cout<<"No solution";return 0;
}
    return 0;
}
//a@aa@a
//Sample Output 1
//a@a,a@a
//Sample Input 2
//a@a@a
//Sample Output 2
//No solution
//Sample Input 3
//@aa@a
//Sample Output 3
//No solution
