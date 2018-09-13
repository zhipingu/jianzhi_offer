#include<iostream>
#include<string>
#include<vector>

using namespace std;

int GetNumSameAsIndex(int a[],int len)
{
	if(!a || len<=0)
		return -1;

	int left=0;
	int right=len-1;
	while(left<=right)
	{
		int mid=(left+right)>>1;
		if(a[mid]==mid)
			return mid;
		else
			if(a[mid]>mid)
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
	}

	return -1;
}
int main()
{
	int a[]={1};
	cout<<GetNumSameAsIndex(a,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
}
