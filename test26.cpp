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

bool equal(double d1,double d2)
{
	if(d1-d2>-0.0000001 && d1-d2<0.0000001)
	{
		return true;
	}
	else return false;
}

bool DoseTree1HasTree2(TreeNode *root1,TreeNode *root2)
{
	if(!root2) return true;
	if(!root1) return false;
	
	if(!equal(root1->key,root2->key))
		return false;
	
	return DoseTree1HasTree2(root1->LeftChild,root2->LeftChild) && DoseTree1HasTree2(root1->RightChild,root2->RightChild);
}

bool HasSubTree(TreeNode *root1,TreeNode *root2)
{
	if(!root2) return true;
	if(!root1) return false;
	
	bool result=false;
	if(equal(root1->key,root2->key)) result=DoseTree1HasTree2(root1,root2);
	if(!result) result=HasSubTree(root1->LeftChild,root2);
	if(!result) result=HasSubTree(root1->RightChild,root2);

	return result;
}

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
	TreeNode *root1=nullptr,*root2=nullptr;
	int a[]={12,10,17,7,11,14,18,13,16};
	int b[]={17,14,18};

	int len=sizeof(a)/sizeof(a[0]);
	int len2=sizeof(b)/sizeof(b[0]);

	for(int i=0;i<len;++i)
	{
		root1=insert(root1,a[i]);
	}

	for(int i=0;i<len2;++i)
	{
		root2=insert(root2,b[i]);
    }
	
	print(root1,4);
	cout<<"==========="<<endl;
	print(root2,2);

	cout<<HasSubTree(root1,root2)<<endl;
	return 0;
}
