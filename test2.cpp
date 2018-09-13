#include<iostream>
#include<vector>
using namespace std;
int duplication(int a[],int len)
{
	if(a==nullptr||len<=0)return -1;
	vector<int> count(len,0);
	for(int i=0;i<len;++i)
	{
		if(count[a[i]]<1)
		++count[a[i]];
		else return a[i];
	}
	return -1;
}
int main()
{
	int a[]={9,2,8,5,1,0,3,4,7};
	cout<<duplication(a,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
}
