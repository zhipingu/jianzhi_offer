#include<iostream>
#include<string>
#include<vector>
#include<queue>

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

void LevelOrder(TreeNode *root)
{
	if(!root)	
		return;
	int ToBePrint=1;
	int NextLevel=0;

	queue<TreeNode *> q;
	q.push(root);

	while(!q.empty())
	{
		TreeNode *tmp=q.front();
		q.pop();
		cout<<tmp->key<<" ";
		--ToBePrint;

		if(tmp->LeftChild)
		{
			q.push(tmp->LeftChild);
			++NextLevel;
		}
		if(tmp->RightChild)
		{
			q.push(tmp->RightChild);
			++NextLevel;
		}

		if(ToBePrint==0)
		{
			cout<<endl;
			ToBePrint=NextLevel;
			NextLevel=0;
		}
	}
}

int main()
{
	TreeNode *root1=nullptr;
	int a[]={12,10,17,7,11,14,18,13,16};

	int len=sizeof(a)/sizeof(a[0]);

	for(int i=0;i<len;++i)
	{
		root1=insert(root1,a[i]);
	}
	
	print(root1,4);
	cout<<"==========="<<endl;

	LevelOrder(root1);
	return 0;
}
