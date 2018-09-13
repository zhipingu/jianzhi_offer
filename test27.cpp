#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

struct treeNode
{
	int key;
	treeNode *leftChild;
	treeNode *rightChild;
};

void mirrorRecursion(treeNode *T)
{
	if(!T) return;
	if(!T->leftChild && !T->rightChild) return;

	treeNode *tmp=T->leftChild;
	T->leftChild=T->rightChild;
	T->rightChild=tmp;

	if(T->leftChild) mirrorRecursion(T->leftChild);

	if(T->rightChild) mirrorRecursion(T->rightChild);

}

void mirrorLoop(treeNode *T)
{
	
}

int main()
{
	return 0;
}
