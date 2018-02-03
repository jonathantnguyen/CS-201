#include <stdio.h>
int main()
{
	int num = 1;
	if(*(char *)&num == 1)
		printf("LITTLE");
	else
		printf("BIG");
}
