#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct ListNode
{
	int key;
	ListNode *next;
	ListNode *sibling;
};

void CopyNode(ListNode *head)
{
	if(!head) 
		return;

	ListNode *tmp=head;

	while(tmp!=nullptr)
	{
		ListNode *NewNode=new ListNode;
		NewNode->key=tmp->key;
		NewNode->next=tmp->next;
		tmp->next=NewNode;
		NewNode->sibling=nullptr;
		tmp=NewNode->next;
	}
}

void CopySibling(ListNode *head)
{
	 ListNode *tmp=head;
	 while(tmp)
	 {

		 ListNode *CloneTmp=tmp->next;
		 if(tmp->sibling)
		 {
			 tmp->next->sibling=tmp->sibling->next;
		 }
		 tmp=CloneTmp->next;
	 }
}

ListNode* ReconnectNode(ListNode *head)
{
	if(!head)
		return nullptr;

	ListNode *CloneHead=head->next;	
	ListNode *CloneTmp=CloneHead;
	ListNode *tmp=CloneHead->next;
	head->next=tmp;

	while(tmp)
	{
		CloneTmp->next=tmp->next;
		CloneTmp=CloneTmp->next;
		tmp->next=CloneTmp->next;
		tmp=tmp->next;
	}

	return CloneHead;

}

ListNode * CopyList(ListNode *head)
{
	CopyNode(head);
	CopySibling(head);
	ListNode *CloneHead=ReconnectNode(head);

	return CloneHead;
}
int main()
{
	ListNode *head=nullptr;
	ListNode *tmp=nullptr;
	for(int i=0;i<10;++i)
	{
		ListNode *NewNode=new ListNode;
		NewNode->key=i;
		NewNode->next=nullptr;
		NewNode->sibling=nullptr;

		if(i==0)
		{
			head=NewNode;
			tmp=head;
		}
		else
		{
			NewNode->sibling=tmp;
			tmp->next=NewNode;
			tmp=tmp->next;
		}

	}
	head->sibling=head->next->next->next;

	ListNode *CloneHead=CopyList(head);

	tmp=head;
	while(tmp)
	{
		cout<<tmp->key<<"--";
		if(tmp->sibling)
			cout<<tmp->sibling->key;
		cout<<" ";

		tmp=tmp->next;
	}
	cout<<endl;

	tmp=CloneHead;
	while(tmp)
	{
		cout<<tmp->key<<"--";
		if(tmp->sibling)
			cout<<tmp->sibling->key;
		cout<<" ";

		tmp=tmp->next;
	}
	cout<<endl;

	return 0;
}
