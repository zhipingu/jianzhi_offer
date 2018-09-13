#include<iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;
void PrintNum(char number[],int len)
{
	int i=0;
	while(i<len&&number[i]=='0')++i;
	if(i==len)cout<<0;
	else while(i<len) cout<<number[i++];
	cout<<" ";

}

void PrintRecursive(char number[],int len,int index)
{
	//到了最后一位'\0'
	if(index==len)
	{
		PrintNum(number,len);
		return;
	}
	else
	{
		for(int i=0;i<10;++i)
		{
			number[index]=i+'0';
			PrintRecursive(number,len,index+1);
		}
	}
}

void print1toMaxOfNdig(int n)
{
	if(n<=0)return;
	char *number=new char[n+1]();

	for(int i=0;i<10;++i)
	{
		number[0]='0'+i;
		PrintRecursive(number,n,1);
	}
	
}

int main(int argc,char **argv)
{

	if(argc!=2)cerr<<"input is invalid"<<endl;
	print1toMaxOfNdig(stoi(argv[1]));
	return 0;
}
