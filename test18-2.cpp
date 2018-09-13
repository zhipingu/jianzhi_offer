#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{
	int key;
	struct node *next;
}Node;

void DeleteDup(Node **phead)
{
	if(!phead||!*phead)
	{
		cout<<"input is nullptr"<<endl;
		return;
	}
	Node *pre=nullptr;
	Node *cur=*phead;
	Node *next=cur->next;
	while(cur)
	{
		bool isdup=false;
		if(next&&cur->key==next->key)
		{
			isdup=true;
		}
		if(!isdup)
		{
			pre=cur;
			cur=next;
			next=next->next;
		}
		else
		{
			int value=cur->key;
			while(cur&&cur->key==value)
			{
				Node *tmp=cur->next;
				delete cur;
				cur=nullptr;
				cur=tmp;
			}
			if(pre==nullptr) *phead=cur;
			else pre->next=cur;
			next=cur->next;

		}
	}
}

int main()
{
	return 0;
}
