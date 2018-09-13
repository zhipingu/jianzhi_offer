#include<iostream>
#include<string>
#include<vector>
#include<stack>

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

void PrintZhiZi(TreeNode *root)
{
	if(!root)
	{
		return;
	}

	int current=0;
	int next=1;
	stack<TreeNode *> level[2];

	level[current].push(root);

	while(!level[0].empty() || !level[1].empty())
	{
		TreeNode *tmp=level[current].top();
		level[current].pop();
		cout<<tmp->key<<" ";

		if(current==0)
		{
			if(tmp->LeftChild)
				level[next].push(tmp->LeftChild);
			if(tmp->RightChild)
				level[next].push(tmp->RightChild);
		}
		else
		{
			if(tmp->RightChild)
				level[next].push(tmp->RightChild);
			if(tmp->LeftChild)
				level[next].push(tmp->LeftChild);
		}

		if(level[current].empty())
		{
			cout<<endl;
			swap(current,next);
		}
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
	
	PrintZhiZi(root);
	return 0;
}
