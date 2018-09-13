#include<iostream>
#include<string>
#include<vector>

using namespace std;


vector<int> Max,Min;

void fun(int a[],int len)
{
	int pre=0,cur=1,next=2;
	int flag=0;

	for(int i=1;i<len;)
	{
		flag=0;//标记i是否已经更新，为0代表没更新

		//尖极大值
		if(a[cur]>a[pre] && a[cur] > a[next])
		{
			Max.push_back(a[cur]);
			++i;
			cur=i;
			pre=cur-1;
			next=cur+1;
			flag=1;
		}
		
		//尖极小值
		else if(a[cur]<a[pre] && a[cur]<a[next])
		{
			Min.push_back(a[cur]);
			++i;
			cur=i;
			pre=cur-1;
			next=i+1;
			flag=1;
		}

		//平极大值
		else if(a[cur]> a[pre] && a[next]==a[cur])
		{
			while(a[next]==a[cur]) 
				++next;
			if(a[cur]>a[next])
				Max.push_back(a[cur]);

			i=next;
			cur=i;
			pre=cur-1;
			next=i+1;
			flag=1;
		}

		//平极小值
		else if(a[cur]<a[pre] && a[next]==a[cur])
		{
			while(a[next]==a[cur])
				++next;
			if(a[cur]<a[next])
				Min.push_back(a[cur]);

			i=next;
			cur=i;
			pre=cur-1;
			next=i+1;
			flag=1;
		}

		if(flag==0)
		{
			++i;
			cur=i;
			pre=cur-1;
			next=cur+1;
		}
	}


	
}
int main()
{
	int a[]={1,2,3,1,7,7,7,4,3,2,16,18,20,10,10,10,10,12,14,24,27};
	int len=sizeof(a)/sizeof(a[0]);

	fun(a,len);

	cout<<"Max:"<<endl;
	for(auto r:Max)
		cout<<r<<" ";
	cout<<endl;

	cout<<"Min:"<<endl;
	for(auto r:Min)
		cout<<r<<" ";
	cout<<endl;
	return 0;
}
