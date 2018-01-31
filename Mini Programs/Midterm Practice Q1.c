#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 6;
	int j = -35;
	printf("%d %d\n",i++,++j);
	i = i << 3;
	j = j >> 4;
	printf("%d %d\n",i,j);
	exit;
}