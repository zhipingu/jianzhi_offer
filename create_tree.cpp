#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode
{	
	int key;
	TreeNode *LeftChild;
	TreeNode *RightChild;

};

TreeNode *insert(TreeNode *root,double key)
{
	
	if(!root) 
	{
		TreeNode *newnode=new TreeNode;
		newnode->key=key;
		newnode->LeftChild=nullptr;
		newnode->RightChild=nullptr;

		root=newnode;
		return root;
	}

	if(key>root->key) root->RightChild=insert(root->RightChild,key);
	else if(key<root->key) root->LeftChild=insert(root->LeftChild,key);
	
	return root;
}

void PrintLevel(TreeNode *root,int level)
{
	if(!root) return;
	if(level<1) return;

	if(level==1) cout<<root->key<<" ";
	else if(level>1)
	{
		PrintLevel(root->LeftChild,level-1);
		PrintLevel(root->RightChild,level-1);
	}
}

void print(TreeNode *root,int levels)
{
	if(!root) return;

	for(int i=1;i<=levels;++i)
	{
		PrintLevel(root,i);
		cout<<endl;
	}
}

int main()
{
	TreeNode *root=nullptr;
	int a[]={12,10,17,7,11,14,18,13,16};

	int len=sizeof(a)/sizeof(a[0]);

	for(int i=0;i<len;++i)
	{
		root=insert(root,a[i]);
	}
	
	print(root,4);
	cout<<"==========="<<endl;

	return 0;
}
