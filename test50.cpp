#include<iostream>
#include<string>
#include<vector>

using namespace std;

char FirstCharAppearOnce(const string &s)
{
	int cnt[256]={0};
	
	for(size_t i=0;i<s.size();++i)
	{
		++cnt[s[i]];
	}

	for(size_t i=0;i<s.size();++i)
	{
		if(cnt[s[i]]==1)
			return s[i];
	}
}
int main()
{
	string s("abcefadkcffb");
	cout<<FirstCharAppearOnce(s)<<endl;
	return 0;
}
