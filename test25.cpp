#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{
	int key;
	struct node *next;
}Node;

Node *merge(Node *head1,Node *head2)
{
	if(!head1) return head2;
	else if(!head2) return head1;
	
	Node *head=nullptr;
	
	if(head1->key>head2->key)
	{
		head=head2;
		head->next=merge(head1,head2->next);
	}
	else 
	{
		head=head1;
		head->next=merge(head1->next,head2);
	}
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
	Node *head1=nullptr,*head2=nullptr;
	Node *tmp=nullptr;
	for(int i=0;i<10;++i)
	{
		Node *newnode=new Node;
		newnode->key=2*i;
		newnode->next=nullptr;

		if(i==0)
		{
			head1=newnode;
			tmp=head1;
		}
		else 
		{
			tmp->next=newnode;
			tmp=tmp->next;
		}

	}
	
	for(int i=0;i<1;++i)
	{
		Node *newnode=new Node;
		newnode->key=2*i;
		newnode->next=nullptr;

		if(i==0)
		{
			head2=newnode;
			tmp=head2;
		}
		else 
		{
			tmp->next=newnode;
			tmp=tmp->next;
		}

	}
	print(head1);
	print(head2);

	Node *head=merge(head1,head2);
	
	print(head);

	return 0;
}
