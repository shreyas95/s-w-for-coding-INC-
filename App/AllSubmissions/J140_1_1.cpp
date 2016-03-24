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


vi ans;

int main() {
    string s; cin >> s;
    int len = s.size();
    int cc = 0; bool check = true;
    for(int i = 0; i < len; ++i) {
        if((s[i] == '@') && (i == 0))
            check = false;
        if((s[i] == '@')) {
            ++cc;
            int j = i+1; bool poss = false;
            //for(j; j < len; ++j) {
                if((s[j] != '@')) {
                    if(s[j+1] != '@') {
                        poss = true;
                    }
                }
            //}
            if(poss) {
                ans.pb(j+1);
            }
            else {
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }
    if(!check)
        cout << "No solution\n";
    else {
        int idx = 0;
        for(int i = 0; i < len; ++i) {
            if(i == ans[idx]) {
                cout << "," << s[i];
                if(idx != (ans.size()-1))
                    ++idx;
            }
            else
                cout << s[i];
        }
        nl();
    }
}
