#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void DoFindAllmCombination(char *pBegin,vector<char> &vec,int m);
void findAllmCombination(char *str,int m)
{
	if(str==NULL||m<=0||strlen(str)<m) return;
	vector<char> vec1;
	DoFindAllmCombination(str,vec1,m);
}
void DoFindAllmCombination(char *pBegin,vector<char> &vec,int m)
{
	if(m==0)
	{
		static int cnt=0;
		cout<<++cnt<<":";
		for(vector<char>::iterator it=vec.begin();it!=vec.end();it++)
			cout<<*it<<' ';
		cout<<endl;
		return;
	}
	if(*pBegin!=0)
	{
		vec.push_back(*pBegin);
		DoFindAllmCombination(pBegin+1,vec,m-1);
		vec.pop_back();
		DoFindAllmCombination(pBegin+1,vec,m);
	}
}
int main()
{
	char *str="after";
	findAllmCombination(str,3);
	return 0;
}

