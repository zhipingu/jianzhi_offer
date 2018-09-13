#include<iostream>
#include<string>
#include<vector>

using namespace std;

void PermutationCore(char *str,char *beg)
{
	static int cnt=0;
	if(*beg=='\0')
		cout<<++cnt<<":"<<str<<endl;

	for(char *tmp=beg;*tmp!='\0';++tmp)
	{
		if(tmp==beg || *tmp!=*beg)
		{
			swap(*beg,*tmp);
			PermutationCore(str,beg+1);
			swap(*beg,*tmp);
		}
	}
}

void permutation(char *a)
{
	if(!a)
		return;
	PermutationCore(a,a);
}

int main()
{
	char str[]="abce";
	permutation(str);
	return 0;
}
