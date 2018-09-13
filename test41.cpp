#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

class Mid
{
	public:
		void insert(int num);
		double GetMid();
	private:
		vector<int> max;
		vector<int> min;
};

void Mid::insert(int num)
{
	if(((max.size()+min.size())&1)==0)
	{
		if(min.size()>0 && num>min[0])
		{
			min.push_back(num);
			push_heap(min.begin(),min.end(),greater<int>());

			num=min[0];

			pop_heap(min.begin(),min.end(),greater<int>());
			min.pop_back();
		}
		max.push_back(num);
		push_heap(max.begin(),max.end());
	}

	else
	{
		if(max.size()>0 && num<max[0])
		{
			max.push_back(num);
			push_heap(max.begin(),max.end());

			num=max[0];

			pop_heap(max.begin(),max.end());
			max.pop_back();
		}
		min.push_back(num);
		push_heap(min.begin(),min.end(),greater<int>());
	}
}

double Mid::GetMid()
{
	if(max.size()+min.size()==0)	
	{
		throw exception();
	}
	if(((max.size()+min.size())&1)==0)
		return (double)(min[0]+max[0])/2;
	else
		return max[0];
}

int main()
{
	Mid m;
	int a[]={6,1,2,9,3,20,14,12};
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<len;++i)
	{
		m.insert(a[i]);
		cout<<m.GetMid()<<endl;
	}
	return 0;
}
