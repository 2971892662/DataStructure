#include <stdlib.h>
#include "singleLinkList_A.h"

//��ͷ�ڵ�ĵ������ʼ��
//��ʼ����Ҫ���ݵĲ����ǣ�ָ�������
bool initSingleLinkList(LNode_A* &L) {
	L = (LNode_A*)malloc(sizeof(LNode_A*));
	L->data = -1;
	L->next = NULL;
	return true;
}

//�п� 
bool isEmpty(LNode_A* L) {
	return (L->next == NULL);
}

//���
int length(LNode_A* L) {
	int i = 0;
	LNode_A* p = L;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//����Ų���
LNode_A* getByNum(LNode_A* L, int i) {
	if (i < 1) {
		return NULL;
	}
	LNode_A* p = L;
	int j = 0;
	while (p != NULL && j < i) {	//�пպ����һ���ж�
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ����
LNode_A* getByVal(LNode_A* L, int val) {
	LNode_A* p = L->next;
	while (p != NULL && p->data != val) {
		p = p->next;
	}
	/*
	* ��ѡ��ӦΪû�ҵ�ʱ��ȻҲ��p=NULL
	if (p == NULL) {
		return NULL;
	}
	*/
	return p;
}

//ָ��λ�򴦲���
bool insertByNum(LNode_A* L, int num, int val) {
	if (num < 1) {
		return false;
	}
	LNode_A* p = L;
	int i = 0;
	while (p != NULL && i < num - 1) {	//��i=num-1ʱֹͣѭ��
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return false;
	}
	LNode_A* s = (LNode_A*)malloc(sizeof(LNode_A));
	s->data = val;
	s->next = p->next;
	p->next = s;
	return true;
}

//��ָ��λ��ɾ��
bool deleteByNum(LNode_A* L, int num, int &val) {
	if (num < 1) {
		return false;
	}
	LNode_A* p = L;
	int j = 0;
	while (p != NULL && j < num - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) {
		return false;
	}
	LNode_A* s = p->next;
	p->next = s->next;
	val = s->data;
	free(s);
	return true;
}

/*
int main() {
	LNode_A* L;
	initSingleLinkList(L);
	insertByNum(L, 1, 1);
	insertByNum(L, 2, 2);
	insertByNum(L, 3, 3);
	int a = -1;
	deleteByNum(L, 2, a);
	cout << a << endl;
	cout << "length:" << length(L) << endl;
}
*/