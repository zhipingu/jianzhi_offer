#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct tree_node
{
	int key;
	tree_node *left_child;
	tree_node *right_child;
};

bool is_symmetrical(tree_node *proot1,tree_node *proot2)
{
	if(proot1== nullptr && proot2 == nullptr)
		return true;
	
	if(proot1 ==nullptr || proot2 == nullptr)
		return false;

	if(proot1->key != proot2->key)
		return false;

	return is_symmetrical(proot1->left_child,proot2->right_child) && is_symmetrical(proot1->right_child,proot2->left_child);
}

int main()
{
	tree_node *root=new tree_node;
	root->key=1;
	root->left_child=new tree_node;

	root->left_child->key=2;
	root->left_child->left_child=nullptr;
	root->left_child->right_child=nullptr;
	

	root->right_child=new tree_node;

	root->right_child->key=4;
	root->right_child->left_child=nullptr;
	root->right_child->right_child=nullptr;

	
	cout<<is_symmetrical(root->left_child,root->right_child)<<endl;
	return 0;
}
