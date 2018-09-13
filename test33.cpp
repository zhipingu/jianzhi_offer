#include<iostream>
#include<string>
#include<vector>

using namespace std;


typedef struct treeNode
{	
	int key;
	struct treeNode *LeftChild;
	struct treeNode *RightChild;

}TreeNode;

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

bool IsLastOrder(int a[],int len)
{
	int root=a[len-1];

	int i=0;
	for(;i<len-1;++i)
	{
		if(a[i]>root)
			break;
	}

	int j=i;
	for(;j<len-1;++j)
	{
		if(a[j]<root)
			return false;
	}

	bool left=true;
	if(i>0)
		IsLastOrder(a,i);
	bool right=true;
	if(i<len-1)
		 IsLastOrder(a+i,len-i-1);

	return left&&right;
	
}

bool IsPostOrder(int a[],int len)
{
	int root=a[0];

	int i=1;
	for(;i<len;++i)
	{
		if(a[i]>root)
			break;
	}

	int j=i;
	for(;j<len;++j)
	{
		if(a[j]<root)
			return false;
	}

	bool left=true;
	if(i>1)
		IsPostOrder(a+1,i-1);
	bool right=true;
	if(i<len)
		IsPostOrder(a+i,len-i);

	return left&&right;
	
}
int main()
{
	
//	int a[]={5,7,6,9,11,10,8};
//	int a[]={7,4,6,5};
	int a[]={10,8,6,9,14,12,16,4};
	int len=sizeof(a)/sizeof(a[0]);

	cout<<IsPostOrder(a,len)<<endl;
	return 0;
}
