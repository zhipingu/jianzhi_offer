
#include<iostream>
#include<string>
#include<vector>
//#include<new>

using namespace std;

struct treenode
{
	int key;
	treenode *leftchild;
	treenode *rightchild;
};

treenode* construct_core(int *prestart,int *preend,int *instart,int  *inend);
treenode * construct(int *prestart,int *instart,int len)
{
	if(prestart==nullptr||instart==nullptr||len<=0)
	{
		perror("input invalid");
		exit(1);
	}
	return construct_core(prestart,prestart+len-1,instart,instart+len-1);
}
treenode* construct_core(int *prestart,int *preend,int *instart,int  *inend)
{
	int root=prestart[0];
	treenode *newroot=new treenode();
	newroot->key=root;
	newroot->leftchild=nullptr;
	newroot->rightchild=nullptr;
	if(prestart==preend)
	{
		if(instart==inend&&*prestart==*instart)
			return newroot;
		else 
		{
			perror("input is invalid");
			exit(1);
		}
	}
	int *root_inorder=instart;
	for(;root_inorder!=inend;++root_inorder)
	{
		if(root==*root_inorder) break;
	}
	if(root_inorder==inend && (*root_inorder)!=root)
	{
		perror("input is invalid");
		exit(1);
	}
	int left_len=root_inorder-instart;
	if(left_len>0)
	newroot->leftchild=construct_core(prestart+1,prestart+left_len,instart,root_inorder-1);
	if(left_len<preend-prestart)
	newroot->rightchild=construct_core(prestart+left_len+1,preend,root_inorder+1,inend);
	return newroot;
}


void preorder(treenode *T)
{
	if(T==nullptr)return;
	else
	{
		cout<<T->key<<endl;
		preorder(T->leftchild);
		preorder(T->rightchild);
	}
	
}

int main()
{
	int pre[]={1,2,4,7,3,5,6,8};
	int inorder[]={4,7,2,1,5,3,6,8};
	treenode *root=construct(pre,inorder,8);
	preorder(nullptr);
	return 0;
}
