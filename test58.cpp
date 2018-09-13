#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Reverse(string& s,size_t begin,size_t end)
{
	if(s.empty())
		return;

//	if(begin>end || begin<0)
//		throw new invalid_argument("index input invalid");

	while(begin<end)
	{
		std::swap(s[begin++],s[end--]);
	}
}

void ReverseWordInString(string& s)
{
	if(s.empty())
		return;

	Reverse(s,0,s.size()-1);

	size_t beg=0,end=0;
	while(beg<s.size())
	{
		while(end<s.size() && s[end]==' ')
			++end;
		beg=end;

		while(end<s.size() && s[end]!=' ')
			++end;
		Reverse(s,beg,end-1);
	}
}
int main()
{
	string s("  hello hzq where are you i am fine thanks and you?");
//	string s(" ");
	ReverseWordInString(s);

	char ch=-1; 
	cout<<hex<<(int)ch<<endl;
	return 0;
}
