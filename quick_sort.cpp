#include<iostream>
#include<string>
#include<vector>

using namespace std;

void insert_sort(int a[],int len)
{
	int i=0;
	for(;i<len-1;++i)
	{
		int j=i+1;
		int tmp=a[j];
		while(j>0&&tmp<a[j-1])
		{
			a[j]=a[j-1];
			--j;
		}
		a[j]=tmp;
	}
}

int median(int a[],int left,int right)
{
	int mid=(left+right)/2;
	if(a[left]>a[mid])std::swap(a[left],a[mid]);//swap参数为引用，所以不用传指针
	if(a[left]>a[right])std::swap(a[left],a[right]);
	if(a[mid]>a[right])std::swap(a[mid],a[right]);
	std::swap(a[mid],a[right-1]);
	return a[right-1];
}

void quick_sort(int a[],int left,int right)
{
	int i=left+1,j=right-2;
	if(right-left>3)
	{
		int pivot=median(a,left,right);
		while(1)
		{
			while(a[i]<pivot)++i;
			while(a[j]>pivot)--j;
		
			if(i<j)
			{
				std::swap(a[i],a[j]);
				++i;
				--j;
			}
			else
			{
				std::swap(a[i],a[right-1]);
				break;
			}
		}
		quick_sort(a,left,i-1);
		quick_sort(a,i+1,right);
	}
	else insert_sort(a+left,right-left+1);

}

void print(int a[],int len)
{
	for(int i=0;i<len;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	int a[]={1,3,8,3,2,20,13,2,0,39,43,21,14,12,16,10,12,13};
	int len=sizeof(a)/sizeof(a[0]);
	quick_sort(a,0,len-1);
	print(a,len);

	return 0;
}
