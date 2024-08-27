#include "ThreadNode.h"
//���Ƕ������������ٱ���������ֱ�ӹ���
void PreThreadNode(ThreadNode* p,ThreadNode* &pre) { //pre��������
	//������������������
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
		//ʹ��pre=p������������PreThreadNode(p->lchild, p)������Ϊ�˷����ҵ����һ���ڵ���д���
		if (p->ltag == 0) {	//�������������������⴦�����������ѭ��
			PreThreadNode(p->lchild, pre);
		}
		PreThreadNode(p->rchild, pre);
	}
}
void createPreThreadNode(ThreadNode* T) {
	if (T != NULL) {
		ThreadNode* pre = NULL;
		PreThreadNode(T, pre);
		if (pre->rchild == NULL) {	//�������һ���ڵ�
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
	for (ThreadNode* p=FirstNode(T); p != NULL; p = nextNode(p)) {	//����forѭ�����ܱ��������õݹ�
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