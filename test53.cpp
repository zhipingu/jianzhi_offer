#include<iostream>
#include<string>
#include<vector>

using namespace std;
int GetFirst(int a[],int beg,int end,int k)
{
	if(beg>end)
		return -1;
//	if(beg==end)
//		return beg;
	
	int  mid=(beg+end)/2;
	if(k>a[mid])
	{
		beg=mid+1;
	}
	else 
		if(k<a[mid])
			end=mid-1;
		else
		{
			if((mid>beg && a[mid-1]!=k)|| mid==beg)
				return mid;
			else
			{
				end=mid-1;
			}
		}

	return GetFirst(a,beg,end,k);
	
}

int GetLast(int a[],int start,int end,int k)
{
	if(start>end)
		return -1;
//	if(start==end)
//		return 0;

	int mid=(start+end)/2;
	if(k>a[mid])
		start=mid+1;
	else
		if(k<a[mid])
			end=mid-1;
		else
		{
			if((mid<end && a[mid+1]!=k)||mid==end)
				return mid;
			else
				start=mid+1;
		}
	return GetLast(a,start,end,k);
}

int TimesOfNumInSortedArray(int a[],int len,int k)
{
	if(!a || len<=0)
		return 0;

	int number=0;
	int first=GetFirst(a,0,len-1,k);
	int last=GetLast(a,0,len-1,k);


	if(last>-1 && first>-1)
		number=last-first+1;
	
	return number;
}
int main()
{
	int a[]={1,2,3,3,3,3,4,5,6,7};
	cout<<TimesOfNumInSortedArray(a,sizeof(a)/sizeof(a[0]),8)<<endl;
	return 0;
}
