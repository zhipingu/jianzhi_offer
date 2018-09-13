#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

struct List
{
	int key;
	List *next;
};

void PrintReverse(List *phead)
{
	if(phead==nullptr)
	{
		cerr<<"phead is nullptr"<<endl;
		return;
	}
	List *tmp=phead;
	stack<List *> nodes;
	while(tmp)
	{
		nodes.push(tmp);
		tmp=tmp->next;
	}
	while(!nodes.empty())
	{
		cout<<nodes.top()->key<<" ";
		nodes.pop();
	}
	cout<<endl;

}

int main()
{
	List *phead=nullptr,*cur=nullptr;
	for(int i=0;i!=1;++i)
	{
		List *tmp=new List;
		tmp->key=2*i;
		tmp->next=nullptr;
		if(phead==nullptr)
		{
			phead=tmp;
			cur=tmp;
		}
		else
		{
			cur->next=tmp;
			cur=tmp;
		}
		
	}
	PrintReverse(phead);
	return 0;
}
