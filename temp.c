#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "list.h"

char* copy_string(char* string){
	  char* new_string =(char *)calloc(strlen(string)+1,sizeof(char));
	    strcpy(new_string,string);
		  return new_string;
}

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

void split(char* string, char* delimiters){

	  char* temp = (char *)calloc(strlen(string)+2,sizeof(char));
	    strncpy(temp,string,strlen(string));
		  temp[strlen(string)] = delimiters[0];
		    char * pch;
			  pch = strtok_new(temp,delimiters);

			    int count = 0;
//				  List* list = make_list();
					
				    while (pch)
						    {

								      char* element = copy_string(pch);
//									        add(list,list->size,element);
									        if(*element=='\0')printf("=====\n");
											else printf("%s\n",element);
											      pch = strtok_new(NULL, delimiters);
												      }
					  free(temp);

					    
					   // return list;

}

int main()
{
	char a[]="#origin#";
	char b[4]={'a'};
//	split(a,"#");
	
	printf("%c\n",*b);
	if(*(b+1)=='\0')printf("====\n");
	if(*(b+2)=='\0')printf("====\n");
	if(*(b+3)=='\0')printf("====\n");

	return 0;
}
