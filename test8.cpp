#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct treenode
{
	int key;
	treenode *leftchild;
	treenode *rightchild;
	treenode *parent;

};

treenode *getnext(treenode *cur)
{
	treenode *next=nullptr;
	if(cur==nullptr)
	{
		perror("input is invalid");
		exit(1);
	}
	if(cur->rightchild!=nullptr)
	{
		treenode *tmp=cur->rightchild;
		while(tmp->leftchild)
		{
			tmp=tmp->leftchild;
		}
		next=tmp;
	}
	else if(cur->parent!=nullptr)
	{
		treenode *tmp=cur;
		while(tmp->parent!=nullptr&&tmp->parent->rightchild==tmp)
		{
			tmp=tmp->parent;
		}
		next=tmp->parent;
	}
		 
	return next;
}

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
	newroot->parent=nullptr;
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
	{
	newroot->leftchild=construct_core(prestart+1,prestart+left_len,instart,root_inorder-1);
	newroot->leftchild->parent=newroot;
	}
	if(left_len<preend-prestart)
	{
	newroot->rightchild=construct_core(prestart+left_len+1,preend,root_inorder+1,inend);
	newroot->rightchild->parent=newroot;
	}
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
	int in[]={4,2,8,5,9,1,6,3,7};
	int pre[]={1,2,4,5,8,9,3,6,7};
	treenode *root=construct(pre,in,sizeof(in)/sizeof(in[0]));
	treenode *tmp=root->rightchild->rightchild;
	treenode *next=getnext(tmp);
	if(!next)
	{
		cout<<"have no next"<<endl;
		exit(0);
	}
	cout<<next->key<<endl;
	return 0;

}
