#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

bool IsPopOrder(int pPush[],int pPop[],int len)
{
	if(!pPush || !pPop || len<=0)
	{
		cerr<<"input is invalid"<<endl;
		return false;
	}

	int *pNextPop=pPop;
	int *pNextPush=pPush;
	bool flag=false;

	stack<int> s;

	while(pNextPop-pPop<len)
	{
		while(s.empty() || *pNextPop!=s.top())
		{
			if(pNextPush-pPush<len)
			{
				s.push(*pNextPush);
				++pNextPush;
			}
			else
				break;
	
		}
	
		if(!s.empty() && *pNextPop==s.top())
		{
			s.pop();
			++pNextPop;
		}
		else
			break;
	}

	if(pNextPop-pPop==len)
		flag=true;

	return flag;
}

int main()
{
	//int pPush[]={1,2,3,4,5};
	//int pPop[]={4,3,5,1,2};
	int pPush[]={1};
	int pPop[]={5};
	cout<<IsPopOrder(pPush,pPop,1)<<endl;
	return 0;
}
