#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void merge(int a[],int len1,int cap1,int b[],int len2)
{
	int len=len1+len2;
	if(a==nullptr||b==nullptr||len1<=0||len2<=0||cap1<=0)
	{
		cerr<<"input is invalid"<<endl;
		return;
	}
	if(len>cap1)
	{
		cerr<<"over capacity"<<endl;
		return;
	}
	while(len1>0&&len2>0)
	{
		if(a[len1-1]>b[len2-1])
		{
			a[len-1]=a[len1-1];
			--len;
			--len1;
		}
		else
		{
			a[len-1]=b[len2-1];
			--len;
			--len2;
		}
	}
	if(len1!=0)
	{
		while(len1>0)
		{
			a[len-1]=a[len1-1];
			--len;
			--len1;
		}
	}
	if(len2!=0)
	{
		while(len2>0)
		{
			a[len-1]=b[len2-1];
			--len;
			--len2;
		}
	}
}

int main()
{
	int a[30]={2,4,10,3,5,8,6,1};
	int b[6]={3,4,2,20,9,0};
	sort(begin(a),begin(a)+8);
	sort(begin(b),end(b));
	merge(a,8,30,b,6);

	int len=8+6;
	for(int i=0;i!=len;++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
