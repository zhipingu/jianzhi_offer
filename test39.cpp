#include<iostream>
#include<string>
#include<vector>
#include<random>

using namespace std;

bool IsMoreThanHalf(int a[],int len,int key)
{
	int times=0;
	for(int i=0;i<len;++i)
		if(a[i]==key) 
			++times;
	if(times<<1>len)
		return true;
	else
		return false;
}

int partion(int a[],int left,int right)
{
	if(!a || right-left<0)	
	{
		cerr<<"input is invalid"<<endl;
		exit(1);
	}
	
	uniform_int_distribution<unsigned> u(left,right);
	default_random_engine e;
	int pivot=u(e);
	swap(a[pivot],a[right]);

	int small=left-1;
	int current=left;
	
	for(;current<right;++current)
	{
		if(a[current]<a[right])
		{
			++small;
			if(small!=current)
			{
				swap(a[small],a[current]);
			}
		}
	}
	++small;
	swap(a[small],a[right]);

	return small;
}

int Qselect(int a[],int left,int right,int k)
{
	if(!a || right-left<0 || k<=0)	
	{
		cerr<<"input is invalid"<<endl;
		exit(1);
	}
	
	int index=partion(a,left,right);
	if(k<index+1)
	{
		right=index-1;
		index=Qselect(a,left,right,k);
	}
	else 
		if(k>index+1)
		{
			left=index+1;
			index=Qselect(a,left,right,k);
		}
		
	return index;
}

int MoreThanHalfNum(int a[],int len)
{
	if(!a || len<=0)
	{
		return 0;
	}

	int tmp=a[0];
	int times=1;
	for(int i=1;i<len;++i)
	{

		if(a[i]==tmp)
			++times;
		else  
			if(times==0)
			{
				tmp=a[i];
				times=1;
			}
			else 
				--times;

	}

	if(IsMoreThanHalf(a,len,tmp))
		return tmp;
	else 
		return 0;
}

int main(int argc,char **argv)
{
//	if(argc!=2) 
//	{
//		cerr<<"input argument is error"<<endl;
//		exit(1);
//	}
//	int k=stoi(argv[1]);
//	cout<<k<<":";
//	int a[]={1,4,5,2,5,8,5,5,5,3,5,5,6,5};
	int a[]={1,4,5,2,3,4};
//	int a[]={4};
	int len=sizeof(a)/sizeof(a[0]);
	
//	int index=Qselect(a,0,len-1,len>>1);
//	if(IsMoreThanHalf(a,len,index))
//		cout<<index<<":"<<a[index]<<endl;
//	else 
//		cout<<"not exist"<<endl;
//	for(int i=0;i<=index;++i)
//		cout<<a[index]<<endl;
//
	cout<<MoreThanHalfNum(a,len)<<endl;
	return 0;
}
