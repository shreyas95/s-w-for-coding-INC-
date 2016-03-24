#include <stdio.h>
#include <string.h>

char s[2000000];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        scanf("%s", s);
        long long ans = 0;
        int len = strlen(s);
        ans = (s[(len-1)]-'0') % (n-1);
        int i;
        for(i = len-2; i >= 0; --i) {
            ans = ans * ((s[i]-'0')%(n-1));
        }
        printf("%I64d\n", ans);
    }
}
