#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode
{	
	int key;
	struct TreeNode *LeftChild;
	struct TreeNode *RightChild;

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

void FindPathCore(TreeNode *root,int key,vector<TreeNode *>& path,int& CurrentSum)
{
	path.push_back(root);
	CurrentSum+=root->key;

	if(!root->LeftChild && !root->RightChild )
	{
		if(CurrentSum==key)
		{
			for(auto beg=path.begin();beg!=path.end();++beg)
				cout<<(*beg)->key<<" ";
			cout<<endl;
		}
	}

	else 
	{
		if(root->LeftChild)
			FindPathCore(root->LeftChild,key,path,CurrentSum);
		if(root->RightChild)
			FindPathCore(root->RightChild,key,path,CurrentSum);
	}

	CurrentSum-=root->key;
	path.pop_back();
		
}

void FindPath(TreeNode *root,int key)
{
	if(!root)
		return;

	vector<TreeNode *> path;
	int CurrentSum=0;
	FindPathCore(root,key,path,CurrentSum);
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

	FindPath(root,33);
	return 0;
}
