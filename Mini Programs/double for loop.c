#include <stdlib.h>
#include <stdio.h>

int main(){
	int n = 9;
	int l = 0;
	int i;
	int j;
	int k = 0;

	for(i = 0; i < n; i++)
	{
		printf("i: %i\n", i );
	
		for(j = i+1; j<=n; j++)
		{
			printf("j: %i\n", j);
			//l += 1;
		//	printf("%i\n", l );
			k++;
		}
	}
	printf("%i\n",k);
exit;
}