#include<iostream>
using namespace std;
bool duplication(int a[],int len,int *dup)
{
	if(a==nullptr||len<=0) return false;
	for(int i=0;i<len;++i)
	{
		if(a[i]<0||a[i]>=len) return false;
	}
	for(int i=0;i<len;++i)
	{
		while(a[i]!=i)
		{
			if(a[i]==a[a[i]])
			{
				*dup=a[i];
				return true;
			}
			swap(a[i],a[a[i]]);
		}
	}
	return false;
}

int main()
{

	int a[8]={4,5,2,7,6,4,3,0};
	int result;
	cout<<duplication(a,sizeof(a)/sizeof(a[0]),&result)<<endl;
	cout<<result<<endl;
	return 0;
}
