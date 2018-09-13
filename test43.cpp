#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;
//见谷歌收藏
int NumberOf1Between1AndN(int n)
{
	int cnt=0;
	//m代表个位，十位，百位.......
	for(int m=1;m<=n;m*=10)
	{
		cnt+=(n/m+8)/10*m+((n/m%10==1)?1:0)*(n%m+1);
	}
	return cnt;
}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cerr<<"input argument"<<endl;
		exit(1);
	}
	int n=stoi(argv[1]);
	cout<<NumberOf1Between1AndN(n)<<endl;
	return 0;
}
