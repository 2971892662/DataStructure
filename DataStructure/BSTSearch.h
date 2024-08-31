#include <stdlib.h>
#include <iostream>
using namespace std;
//¶þ²æÅÅÐòÊ÷
struct BSTNode {
	int data;
	BSTNode* left, * right;
};
void BSTInsert(BSTNode* &T, int val);
BSTNode* createBSTree(int* a, int len);
void preBSTTraverse(BSTNode* root);
