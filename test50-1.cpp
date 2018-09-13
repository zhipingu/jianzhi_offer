#include<iostream>
#include<string>
#include<vector>

using namespace std;

void DeleteCharAtSecondStr(string &s1,const string &s2)
{
	if(s1.size()==0 || s2.size()==0)
		return;

	int *cnt=new int[256]();
	for(size_t i=0;i<s2.size();++i)
		++cnt[s2[i]];
	string tmp;	
	int j=0;
	for(size_t i=0;i<s1.size();++i)	
	{
		if(cnt[s1[i]]==0)
		{
			tmp.push_back(s1[i]);
			++j;
		}

	}
	s1=tmp;
	delete[] cnt;
}
int main()
{
	string s1("abcefakdbfjdagbde");
	string s2("abc");
	DeleteCharAtSecondStr(s1,s2);
	cout<<s1<<endl;
	return 0;
}
