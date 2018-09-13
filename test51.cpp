#include<iostream>
#include<string>
#include<vector>

using namespace std;

int InversePairsCore(int a[],int beg,int end)
{
	if(beg==end)
		return 0;

	int mid=(beg+end)/2;
	int left=InversePairsCore(a,beg,mid);
	int right=InversePairsCore(a,mid+1,end);
	
	int cnt=0;
	int i=mid;
	int j=end;

	int *tmp=new int[end-beg+1]();
	int index=end-beg;

	while(i>=beg && j>mid)
	{
		if(a[i]>a[j])
		{
			cnt+=j-mid;
			tmp[index--]=a[i--];
		}
		else
		{
			tmp[index--]=a[j--];
		}
	}

	while(i>=beg)
		tmp[index--]=a[i--];

	while(j>mid)
		tmp[index--]=a[j--];

	index=0;
	for(int i=beg;i<=end;++i)
		a[i]=tmp[index++];

	delete[] tmp;
	return left+right+cnt;

}

int InversePairs(int a[],int len)
{
	if(!a || len<=0)
	{
		return 0;
	}

	return InversePairsCore(a,0,len-1);
}

int main()
{
//	int a[]={7,5,6,4};
//	int a[]={1,2,3,4,5,6};
//	int a[]={5,4,3,4,2,1,3,5};
	int a[]={5};
	int len=sizeof(a)/sizeof(a[0]);
	cout<<InversePairs(a,len)<<endl;
	return 0;
}
