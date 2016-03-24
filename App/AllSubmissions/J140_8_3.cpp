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

int dp[9000000];

ll solve(ll x) {
    if(dp[x] != 0)
        return dp[x];
    if(x == 2)
        return 4;
    return dp[x] = solve(x-1) + x;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; sll(n);
        cout << solve(n) << endl;
    }
}
