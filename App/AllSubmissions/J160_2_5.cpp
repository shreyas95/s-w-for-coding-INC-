#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,u,q=0;
    int A[5];
    int i,m,p,sum=0,j;
    for(i=0;i<5;i++)
    {
        scanf("%d\t",&A[i]);
    }
    scanf("%d",&k);
    for(i=0;i<5;i++)
    {
        scanf("%d",&p);
        q=p*A[i];
        sum=sum+q;
        if(sum>k)
        {
            printf("%d\t%d\n",p,sum);
            break;
        }
        else
        {
            printf("%d\t%d\n",p,sum);
        }
    }
    return 0;
}
