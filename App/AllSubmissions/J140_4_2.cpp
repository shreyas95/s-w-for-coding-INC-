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

ll maxx(ll a, ll b) {
    if(a > b)
        return a;
     else return  b;
}

map<ll, ll> dp;

ll solve(ll x) {
    if(dp[x] != 0)
        return dp[x];
    ll  ans = x;
    while(x != 1) {
        if((x % 2) == 1) {
            x *= 3;
            x += 1;
        }
        else
            x /= 2;
        ans = max(ans, x);
    }
    return ans;
}


int main() {
    int t; sd(t);
    while(t--) {
        ll n; sll(n);
        cout << solve(n) << endl;
    }
}
