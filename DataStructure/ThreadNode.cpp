#include "ThreadNode.h"
//得是二叉树建立完再遍历而不是直接构造
void PreThreadNode(ThreadNode* p,ThreadNode* &pre) { //pre引用类型
	//创建先序线索二叉树
	if (p != NULL) {
		if (p->lchild == NULL) {
			p->ltag = 1;
			p->lchild = pre;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p;
		//使用pre=p而不是在下面PreThreadNode(p->lchild, p)，这是为了方便找到最后一个节点进行处理
		if (p->ltag == 0) {	//先序线索二叉树的特殊处理，否则可能死循环
			PreThreadNode(p->lchild, pre);
		}
		PreThreadNode(p->rchild, pre);
	}
}
void createPreThreadNode(ThreadNode* T) {
	if (T != NULL) {
		ThreadNode* pre = NULL;
		PreThreadNode(T, pre);
		if (pre->rchild == NULL) {	//处理最后一个节点
			pre->rtag = 1;
		}
	}
}
ThreadNode* FirstNode(ThreadNode* T) {
	return T;
}
ThreadNode* nextNode(ThreadNode* T) {
	if (T->ltag == 0) {
		return T->lchild;
	};
	return T->rchild;
}
void preOrder(ThreadNode* T) {
	for (ThreadNode* p=FirstNode(T); p != NULL; p = nextNode(p)) {	//依靠for循环就能遍历而不用递归
		cout << p->data << endl;
	}
}
/*
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
*/