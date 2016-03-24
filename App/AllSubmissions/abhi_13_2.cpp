#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int main()
{
	int p, i, n, result, c;
	scanf("%d", &p);				/* get # of data sets */
	for (i = 0; i < p; i++) {
		scanf("%d",&n);	
		result = n;
		while(n > 1){
				/*
				 * Odd value?
				 */
				if(n & 1){
					n = 3*n + 1;
				} else {
					/*
					 * Even value
					 */
					n /= 2;
				}
				/*
				 * Do we have a new max?
				 */
				if(n > result){
					 result = n;
				}
			}
		printf("%d\n",result);
	}
	return 0;
}
