#include<iostream>
#include<string>
#include<vector>

using namespace std;

void TimesAppearInStr2(const string &s1,const string &s2)
{
	if(!s1.size() || !s2.size())
		return;

	int cnt[256]={0};

	for(size_t i=0;i<s2.size();++i)
		++cnt[s2[i]];

	for(size_t i=0;i<s1.size();++i)
		cout<<s1[i]<<":"<<cnt[s1[i]]<<endl;
}

int main()
{
	string s1="abc";
	string s2="kdfadkfbkdjsakbdccbbadkfabfdc";

	TimesAppearInStr2(s1,s2);
	return 0;
}
