#include<iostream>
#include<string>
#include<vector>

using namespace std;

void ReOrder(int a[],int len)
{
	if(a==nullptr || len<=0)
	{
		cerr<<"input is invalid"<<endl;
		return;
	}
	int left=0,right=len-1;
	while(left<right)
	{
		while(left<right && (a[left]&0x1)==1)
		{
			++left;
		}
	
		while(left<right && (a[right]&0x1)==0)
		{
			--right;
		}

		if(left<right) 
		{
			swap(a[left],a[right]);
			//++left;
			//--right;
		}
	}


}

int main()
{
	int a[]={4,64,43,23,12,32,57,86,5,75,64,80,68,59};
	int len=sizeof(a)/sizeof(a[0]);
	ReOrder(a,sizeof(a)/sizeof(a[0]));
	for(int i=0;i<len;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;

}
