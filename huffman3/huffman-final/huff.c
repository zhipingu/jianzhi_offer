#include"helper.h"

int main()
{

	int flag  = 0;		
	char ifname[256], ofname[256];		// Save input and output file names

	printf("Please input the infile name:\n ");
	rewind(stdin);		// Empty the standard input stream to prevent interference with the gets function to read the file name
	if(scanf("%s",ifname)==0)
	{
        printf("input error\n");
        exit(1);
	}
    strcpy(ofname,ifname);
    strcat(ofname,".huff");
	
	printf("Compressing~{!-!-~}\n");
	flag = compress(ifname, ofname);	// Compressed, the return value is used to determine if the file name does not exist.
	
	if (flag == -1)
		printf("Sorry, infile \"%s\" doesn't exist!\n", ifname);		// If the flag is ~{!.~}-1~{!/~} then the input file does not exist
	else
		printf("Operation is done!\n");
	
	return 0;
}




