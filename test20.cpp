#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool ScanUnsigned(const char **str)
{
	const char *first=*str;
	while(**str>='0'&&**str<='9')++*str;
	return *str>first;
}

bool ScanInteger(const char **str)
{
	if(**str=='+'||**str=='-')
		++(*str);
	return ScanUnsigned(str);
}

bool IsNumeric(const char *str)
{
	if(str==nullptr) return false;
	bool numeric=ScanInteger(&str);
	if(*str=='.')
	{
		++str;
		numeric= ScanUnsigned(&str) || numeric ;
	}
	if(*str=='e' || *str=='E')
	{
		++str;
		numeric=numeric && ScanInteger(&str);
	}
	return numeric && *str=='\0';
}

int main(int argc,const char **argv)
{

	cout<<IsNumeric(argv[1])<<endl;
	return 0;
}
