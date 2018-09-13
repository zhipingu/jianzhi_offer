#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Reverse(string& s,size_t begin,size_t end)
    {
        if(s.empty()|| begin>=end)
            return;

        size_t i=begin,j=end;
        while(i<j)
        {
            std::swap(s[i++],s[j--]);
        }
    }

    string ReverseSentence(string str) {
        if(str.empty())
		return string("");

        Reverse(str,0,str.size()-1);

        size_t beg=0,end=0;
        while(beg<str.size())
        {
            while(str[end]!=' ' && end!=str.size()-1)
                ++end;
            Reverse(str,beg,end==str.size()-1?end:end-1);
            beg=++end;
        }
        
        return str;


    }

int main()
{
	string s("hello world ni hao ma");
	s=ReverseSentence(s);
	cout<<s<<endl;
}

