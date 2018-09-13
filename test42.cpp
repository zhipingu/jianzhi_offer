#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int FindGreatestSumOfSubArray(int a[],int len)
{
	if(!a || len<=0)
	{
		cerr<<"input is invalid"<<endl;
		exit(1);
	}

	int max=0;
	int CurSum=0;

	for(int i=0;i<len;++i)
	{
		if(CurSum<0)
			CurSum=a[i];
		else
			CurSum+=a[i];

		if(CurSum>max)
			max=CurSum;
	}

	return max;
}
int main()
{
	int a[]={1,-2,3,10,-4,7,2,-5};
	int len=sizeof(a)/sizeof(a[0]);
	cout<<FindGreatestSumOfSubArray(a,len)<<endl;
	return 0;
}
