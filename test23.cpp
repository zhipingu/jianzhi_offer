#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{
	int key;
	struct node *next;
}Node;

Node *MeetNode(Node *head)
{
	if(head==nullptr)
	{
		cerr<<"input is invalid"<<endl;
		return nullptr;
	}

	Node *fast=head;
	Node *slow=head;

	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) return fast;
	}

	return nullptr;

}

Node *EntryNodeOfLoop(Node *head)
{
	if(head==nullptr)
	{
		cerr<<"input in invalid"<<endl;
		return nullptr;
	}

	Node *meetNode=MeetNode(head);
	if(meetNode==nullptr) return nullptr;

	Node *tmp=meetNode;
	int loopcnt=1;

	while(tmp->next!=meetNode)
	{
		tmp=tmp->next;
		++loopcnt;
	}

	Node *first=head;
	for(int i=0;i<loopcnt;++i)
	{
		if(first) first=first->next;
		else break;
	}

	Node *second=head;
	while(first!=second)
	{
		first=first->next;
		second=second->next;
	}

	return first;
	
}	


int main(int argc,char **argv)
{
	int N=stoi(argv[1]);
	Node *head=nullptr;
	Node *tmp=nullptr;
	Node *the_Nth=nullptr;
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
			if(i==N) the_Nth=newnode;
			tmp->next=newnode;
			tmp=tmp->next;
		}

	}
	//tmp->next=the_Nth;
	Node *entry=EntryNodeOfLoop(head);
	if(entry) cout<<entry->key<<endl;
	return 0;
}
