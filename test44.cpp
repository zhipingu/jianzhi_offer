#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstdlib>

using namespace std;
int numOfDigit(int digits)
{
	if(digits<=0)
		return 0;
	
	if(digits==1)
		return 10;
	
	if(digits>1)
	{
		return 9*pow(10,digits-1);
	}
}

int beginNumOfDigits(int digits)
{
	if(digits<=0)
	{
		cerr<<"beginNumOfDigits input is invalid"<<endl;
		exit(1);
	}

	if(digits==1)
		return 0;

	else
	{
		return pow(10,digits-1);
	}
}
int digitAtIndexInThis(int digits,int index)
{
	int remainder=index%digits;
	int numbers=index/digits;

	int beginNum=beginNumOfDigits(digits);
	int result=beginNum+numbers;
	//下标从0开始，所以digits-1-remainder
	return result/(int)pow(10,digits-remainder-1)%10;
}
int digitAtIndex(int index)
{
	if(index<0)
		return -1;

	int digits=1;
	while(1)
	{
		int cnt=numOfDigit(digits);
		if(index<cnt*digits)
			return digitAtIndexInThis(digits,index);
		else	
		{	
			index-=cnt*digits;
			++digits;
		}
	}
}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cerr<<"input argument invalid"<<endl;
		exit(1);
	}

	int n=stoi(argv[1]);
	cout<<digitAtIndex(n)<<endl;
	return 0;
}
