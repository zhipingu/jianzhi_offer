#include<iostream>
#include<string>
#include<vector>

using namespace std;

int findmin(int a[],int len)
{
	if(a==nullptr||len<=0)
	{
		cerr<<"input is invalid"<<endl;
		exit(1);
	}
	int left=0,right=len-1;
	int mid=left;
	while(a[left]>=a[right])
	{
		mid=(left+right)/2;
		if(a[left]==a[mid]&&a[mid]==a[right])
		{
			
			for(int i=left+1;i<=right;++i)
			{
				if(a[i]<a[mid])mid=i;
			}
			return a[mid];
		}
		else if(a[mid]>=a[left])left=mid;
			 else if(a[mid]<=a[right])right=mid;
		if(right-left==1)
		{
			mid=right;
			break;
		}
	}
	return a[mid];
}

int main()
{
	int a[]={1};
	cout<<findmin(nullptr,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
}
