#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,u,q=0;
    int A[5]={1,2,3,4,5};
    int i,m,p,sum=0,j;
    printf("\n Performing easy selection");
    printf("\n Addition of numbers when numbers are repeated");
    printf("\n Enter the threshold sum k");
    scanf("%d",&k);
    for(i=0;i<5;i++)
    {
        printf("\n Enter the index value");
        scanf("%d",&m);
        printf("\n Enter the number of times you want to add the number");
        scanf("%d",&p);
        q=p*A[m];
        sum=sum+q;
        if(sum>k)
        {
            printf("\n Addition is:%d",sum);
            printf("\n Sum is exceeded the given value");
            break;
        }
        else
        {
            printf("\n Addition is:%d",sum);
        }
    }
    return 0;
}
