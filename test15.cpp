#include<iostream>
#include<string>
#include<vector>

using namespace std;

int numof1(int num)
{
	int count=0;
	while(num>0)
	{
		num=num&(num-1);
		++count;
	}
	return count;
}

int main()
{
	cout<<numof1(0xcf8)<<endl;
	return 0;
}
