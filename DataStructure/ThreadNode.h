#include <stdlib.h>
#include <iostream>
using namespace std;
struct ThreadNode {
	int data;
	ThreadNode* lchild, * rchild;
	int ltag, rtag;
};
//ÏßË÷¶þ²æÊ÷
void PreThreadNode(ThreadNode* p, ThreadNode*& pre);
void createPreThreadNode(ThreadNode* T);
ThreadNode* FirstNode(ThreadNode* T);
ThreadNode* nextNode(ThreadNode* T);
void preOrder(ThreadNode* T);