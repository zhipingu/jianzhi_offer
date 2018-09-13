#include<iostream>
#include<string>
#include<vector>

using namespace std;

int FindMissNum(int a[],int len)
{
	if(!a || len<=0)
		return -1;

	int left=0;
	int right=len-1;

	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==mid)
			left=mid+1;
		else
		{
			if(mid==0 || a[mid-1]==mid-1)
				return mid;
			else
				right=mid-1;
		}
	}

	if(left==len)
		return len;

	return -1;
}
int main()
{
//	int a[]={0,1,2,3,4,5,6,7,8,9};
	int a[]={1};
	cout<<FindMissNum(a,1)<<endl;
	return 0;
	}
