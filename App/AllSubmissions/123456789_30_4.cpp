#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int main()
{
	int p, i, i1, b, result, c;
	scanf("%d", &p);				/* get # of data sets */
	for (i = 0; i < p; i++) {
		scanf("%d ",&b);	
		result = 0;
		while (isdigit(c = getchar())) {
			result = (result + c - '0') % (b - 1);
		}
		printf("%d\n",result);
	}
	return 0;
}
