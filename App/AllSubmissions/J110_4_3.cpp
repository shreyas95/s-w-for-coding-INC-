#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, p, tmp, i;
    scanf("%d", &t);
    while(t != 0)
    {
        scanf("%d", &tmp);
        if(tmp == 1)
        {
            printf("%d\n", 2);
            t--;
            continue;
        }
        if(tmp == 2)
        {
            printf("%d\n", 4);
            t--;
            continue;
        }
        n = 2; p = 4;
        tmp = tmp-2;
        for(i=0; i<tmp; i++)
        {
            n++;
            p = p+n;
        }
        printf("%d\n", p);
        t--;
    }
    return 0;
}
