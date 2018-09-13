#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{
	int key;
	struct node *next;
}Node;

Node *ReverseList(Node *head)
{
	if(!head)
	{
		cerr<<"input is invalid"<<endl;
		return nullptr;
	}
	Node *pre=nullptr;
	Node *cur=head;
	Node *next=nullptr;

	while(cur)
	{
		next=cur->next;
		if(!next) head=cur;
		cur->next=pre;
		pre=cur;
		cur=next;

	}

	return head;
}

Node *ReverseCore(Node *pre,Node *cur)
{
	if(!cur) return pre;

	Node *next=cur->next;
	cur->next=pre;

	Node *head=ReverseCore(cur,next);

	return head;
}

Node *ReverseListRecursion(Node *head)
{
	if(!head)
	{
		cerr<<"input is invalid"<<endl;
		return nullptr;
	}
	Node *pre=nullptr;
	head=ReverseCore(pre,head);
	
	return head;

}

void print(Node *head)
{
	if(!head) 
	{
		cerr<<"input is invalid"<<endl;
		return;
	}
	
	Node *tmp=head;
	while(tmp)
	{
		cout<<tmp->key<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
	
}

int main()
{

	Node *head=nullptr;
	Node *tmp=nullptr;
	for(int i=0;i<1;++i)
	{
		Node *newnode=new Node;
		newnode->key=i;
		newnode->next=nullptr;

		if(i==0)
		{
			head=newnode;
			tmp=head;
		}
		else 
		{
			tmp->next=newnode;
			tmp=tmp->next;
		}

	}

	print(head);

	//head=ReverseList(head);
	head=ReverseListRecursion(head);
	print(head);

	return 0;
}
