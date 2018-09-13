#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p=(int *)malloc(sizeof(int));
	free(p);
	p=NULL;
	free(p);
	printf("dkfjdkfjdk\n");
	return 0;
}
