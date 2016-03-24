#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(n) scanf("%d", &n)
#define sll(n) scanf("%I64d", &n)
#define pll(n) printf("%I64d", &n)
#define nl() printf("\n")
#define pd(n) printf("%d", &n)
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

bool prime[1000000];

set<int> primes;

int main() {
    /*for(int i = 2; i*i <= 1000000000; ++i) {
        if(!prime[i]) {
            primes.insert(i);
            for(int j = 2*i; j <= 1000000; j += i)
                prim[j] = true;
        }
    }*/
    int t; sd(t);
    while(t--) {
        int n, k; sd(n); sd(k);
        int a[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int minmod = k;
        for(int i = 0; i < n; ++i) {
            if(k % a[i] == 0) {
                minmod = 0;
                break;
            }
            else {
                minmod = min(k % a[i], minmod);
            }
        }
        if(minmod == 0)
            cout << k << endl;
        else    cout << k-minmod << endl;
    }
}
