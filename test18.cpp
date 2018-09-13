#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct node
{	
	int key;
	struct node *next;
}Node;

void DeleteNode(Node **phead,Node *pToBeDeleted)
{
	if(!phead||!pToBeDeleted)
	{
		cerr<<"input is invalid"<<endl;
		return;
	}
	if(pToBeDeleted->next!=nullptr)
	{
		Node *next=pToBeDeleted->next;
		pToBeDeleted->key=next->key;
		pToBeDeleted->next=next->next;

		delete next;
		next=nullptr;
	}
	else if(pToBeDeleted==*phead)
	{
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
		*phead=nullptr;
	}
	else 
	{
		Node *tmp=*phead;
		while(tmp->next!=pToBeDeleted)tmp=tmp->next;
		delete pToBeDeleted;
		tmp->next=nullptr;
		pToBeDeleted=nullptr;
	}
}

void print(Node *head)
{
	if(!head)
	{
		cout<<"list is empty"<<endl;
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

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cerr<<"argument is missing"<<endl;
		return 0;
	}
	Node *head=nullptr;
	Node *tmp=head;
	for(int i=0;i<10;++i)
	{
		Node *newnode=new Node;
		newnode->key=2*i;
		newnode->next=nullptr;

		if(i==0) 
		{
			head=newnode;
			tmp=head;
		}
		else
		{
			tmp->next=newnode;
			tmp=newnode;
		}
		//newnode=nullptr;
		
	}
	print(head);
	
	tmp=head;
	while(tmp&&tmp->key!=stoi(argv[1]))tmp=tmp->next;
	if(tmp)
	{
		DeleteNode(&head,tmp);
	}
	print(head);
	return 0;
}
