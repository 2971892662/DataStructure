#include "BSTSearch.h"
void BSTInsert(BSTNode* &T, int val) {
	if (T == NULL) {
		T = (BSTNode*)malloc(sizeof(BSTNode));
		T->data = val;
		T->left = NULL;
		T->right = NULL;
		return;
	}
	if (T->data == val) {
		return;
	}
	BSTNode* tem = (BSTNode*)malloc(sizeof(BSTNode));
	tem->data = val;
	tem->left = NULL;
	tem->right = NULL;
	if (T->data < val) {
		BSTInsert(T->right, val);
	}
	else {
		BSTInsert(T->left, val);
	}
}
BSTNode* createBSTree(int* a, int len) {
	int i = 0;
	BSTNode* root=NULL;
	for (i; i < len; i++) {
		BSTInsert(root, a[i]);
	}
	return root;
}
void preBSTTraverse(BSTNode* root) {
	if (root != NULL) {
		preBSTTraverse(root->left);
		cout << root->data << " ";
		preBSTTraverse(root->right);
	}
}
/*
int main() {
	int a[] = { 11,2,13,4,-2 };
	BSTNode* res = createBSTree(a, 5);
	preBSTTraverse(res);
}
*/