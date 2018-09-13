#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{
	int key;
	struct node *next;
}Node;

Node *FindKthToTail(Node *head,int k)
{
	if(head==nullptr || k<=0)
	{
		cerr<<"input is invalid"<<endl;
		return nullptr;
	}

	Node *first=head,*second=nullptr;
	
	for(int i=1;i<k;++i)
	{
		if(first->next) first=first->next;
		else return nullptr;
	}

	second=head;

	while(first->next)
	{
		first=first->next;
		second=second->next;
	}

	return second;


}

Node *FindMid(Node *head)
{
	if(!head) 
	{
		cerr<<"input is invalid"<<endl;
		return nullptr;
	}

	Node *fast=head;
	Node *slow=head;

	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	return slow;
}

int main(int argc,char **argv)
{
	Node *head=nullptr;
	Node *tmp=nullptr;

	for(int i=0;i<11;++i)
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

	Node *result=FindKthToTail(head,stoi(argv[1]));
	if(result) cout<<result->key<<endl;

	result=FindMid(head);
	if(result) cout<<result->key<<endl;

	return 0;
}
