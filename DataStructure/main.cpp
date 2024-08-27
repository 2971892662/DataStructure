#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ThreadNode.h"

using namespace std;

int main() {
	ThreadNode* a = (ThreadNode*)malloc(sizeof(ThreadNode));
	a->data = 1;
	a->ltag = 0;
	a->rtag = 0;
	a->lchild = NULL;
	a->rchild = NULL;
	ThreadNode* b = (ThreadNode*)malloc(sizeof(ThreadNode));
	b->data = 2;
	b->ltag = 0;
	b->rtag = 0;
	b->lchild = NULL;
	b->rchild = NULL;
	ThreadNode* c = (ThreadNode*)malloc(sizeof(ThreadNode));
	c->data = 3;
	c->ltag = 0;
	c->rtag = 0;
	c->lchild = NULL;
	c->rchild = NULL;
	a->lchild = b;
	a->rchild = c;
	createPreThreadNode(a);
	preOrder(a);
}