#include <stdlib.h>
#include <stdio.h>

int main(){
	int n = 9;
	int l = 0;

	for(int i = 0; i < n; i++)
		for(int j = i+1; j<=n; j++)
			l += 1;
		printf("%i\n", l );
exit;
}