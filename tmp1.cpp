#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n=45678;
	char str[50];
	sprintf(str,"%d",n);
	char *tmp=str;
	while(*tmp++!='\0')
		cout<<*tmp<<endl;

	return 0;
}
