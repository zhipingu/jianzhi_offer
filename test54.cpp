// KthNumInBinTree.cpp : Defines the entry point for the console application.
//

#include<iostream>
using namespace std;

struct TreeNode {
	int key;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		key(x), left(NULL), right(NULL) {
	}
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot || k <= 0)
		return nullptr;

	static int cnt = 0;
	TreeNode *result = nullptr;

	if (pRoot->left)
		result = KthNode(pRoot->left, k);

	if (!result)
	{
		++cnt;
		if (k == cnt)
		{
			result = pRoot;
			return result;
		}
	}

	if (!result && pRoot->right)
		result = KthNode(pRoot->right, k);

	return result;
}

TreeNode *insert(TreeNode *pRoot, int key)
{
	if (!pRoot)
	{
		TreeNode *newroot = new TreeNode(key);
		return newroot;
	}

	if (key > pRoot->key)
		pRoot->right=insert(pRoot->right, key);

	else
		if (key < pRoot->key)
			pRoot->left=insert(pRoot->left, key);

	return pRoot;
}

int main()
{
	int a[] = { 8,6,10,5,7,9,11 };
	int len = sizeof(a) / sizeof(a[0]);

	TreeNode *pRoot=nullptr;
	for (int i = 0; i < len; ++i)
	{
		pRoot = insert(pRoot, a[i]);
	}
	
	TreeNode *result = KthNode(pRoot, 2);
	cout<<result->key << endl;
    return 0;
}


