#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

int FindNumAppearOnce(int a[],int len)
{
	if(!a || len<=0)
		throw new invalid_argument("invalid input");
	
	int bitSum[32]={0};
	for(int i=0;i<len;++i)
	{
		int bit=1;
		for(int j=0;j<32;++j)
		{
			if(a[i]&bit)
				bitSum[j]+=1;
			bit<<=1;
		}
	}
	
	int result=0;
	for(int i=31;i>=0;--i)
	{
		result<<=1;
		result+=bitSum[i]%3;
		//如果后面还有数字要加,对比result左移代码位置
	//	if(i>0)
	//		result<<=1;
	}
	
	return result;
}

int main()
{
	int a[]={-3,-3,-3,0,0,0,4,4,4,7,6,6,6};
	int len=sizeof(a)/sizeof(a[0]);
	cout<<FindNumAppearOnce(a,len)<<endl;
	return 0;
}
