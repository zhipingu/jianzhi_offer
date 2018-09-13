#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>
typedef struct A AA;

typedef struct A
{
	int key;
	AA *next;

}AA;
char *strtok_new(char * string, char const * delimiter){
	  static char *source = NULL;
	    char *p, *riturn = 0;
		  if(string != NULL)         source = string;
		    if(source == NULL)         return NULL;

			  if((p = strpbrk (source, delimiter)) != NULL) {
				      *p  = 0;
					      riturn = source;
						      source = ++p;
							    }
			    return riturn;
}

void fun33(int *p)
{
	*p=4;
}
int main()
{
	int i=9;
	fun33(&i);
	printf("%d\n",i);
	return 0;
}
