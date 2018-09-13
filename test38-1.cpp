#include<iostream>
#include<string>
#include<vector>

using namespace std;

void combinationCore(char *str,int m,vector<char> &cvec)
{
	static int cnt=0;
	if(m==0)
	{
		cout<<++cnt<<":";
		for(auto beg=cvec.begin();beg!=cvec.end();++beg)
			cout<<*beg<<" ";
		cout<<endl;
		return;
	}

	if(*str!='\0')
	{
		cvec.push_back(*str);
		combinationCore(str+1,m-1,cvec);
		cvec.pop_back();
		combinationCore(str+1,m,cvec);
	}
}

void combination(char *str,int m)
{
	if(!str || m<=0)
		return;

	vector<char> cvec;

	combinationCore(str,m,cvec);

}

int main()
{
	char *str="abcde";
	combination(str,4);
	return 0;
}
