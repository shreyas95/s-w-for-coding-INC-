#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, B, a;
    char sc = 0;
    scanf("%d", &t);
    while(t != 0)
    {
        a = 0;
        scanf("%d", &B);
        while(sc < '0')
            sc = getchar();
        while(sc != '\n')
        {
            a = a*B + sc - '0';
            a = a%(B-1);
            sc = getchar();
        }
        printf("%d\n",a);
        t--;
    }
    return 0;
}
