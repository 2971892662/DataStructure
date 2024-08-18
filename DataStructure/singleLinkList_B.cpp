#include <stdlib.h>
#include "singleLinkList_B.h"

//初始化
bool initLNode_B(LNode_B*& L) {
	L = NULL;
	return true;
}
//表长
int length(LNode_B* L) {
	int i = 0;
	LNode_B* p = L;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//判空
bool isEmpty(LNode_B* L) {
	return (L == NULL);
}

//按位查找
LNode_B* getByNum(LNode_B* L, int num) {
	if (num < 1) {
		return NULL;
	}
	int i = 1;
	LNode_B* p = L;
	while (p != NULL && i < num) {
		i++;
		p = p->next;
	}
	return p;
}

//按值查找
LNode_B* getByVal(LNode_B* L, int val) {
	LNode_B* p = L;
	while (p != NULL && p->data != val) {
		p = p->next;
	}
	return p;
 }

//按位插入
bool insertByNum(LNode_B* &L, int num,int val) {
	if (num < 1) {
		return false;
	}
	if (num == 1) {
		LNode_B* s = (LNode_B*)malloc(sizeof(LNode_B));
		s->data = val;
		s->next = L;	//不是NULL
		L = s;
		return true;
	}
	LNode_B* p = L;
	int i = 1;	//i取1而不是0
	while (p != NULL && i < num-1) {
		i++;
		p = p->next;
	}
	LNode_B* s = (LNode_B*)malloc(sizeof(LNode_B));
	s->data = val;
	s->next = p->next;
	p->next = s;
	return true;
}

//按位删除
bool deleteByNum(LNode_B* &L, int num, int& val) {
	if (num < 1) {
		return false;
	}
	if (num == 1) {
		LNode_B* s = L;
		val = s->data;
		L = s->next;
		free(s);
		return true;
	}
	LNode_B* p = L;
	int i = 1;
	while (p != NULL && i < num - 1) {
		i++;
		p = p->next;
	}
	if (p == NULL || p->next == NULL) {
		return false;
	}
	LNode_B* s = p->next;
	p->next = s->next;
	val = s->data;
	free(s);
	return true;
}

/*
int main() {
	LNode_B* L;
	initLNode_B(L);
	insertByNum(L, 1, 1);
	insertByNum(L, 1, 2);
	insertByNum(L, 1, 3);
	int a = -1;
	deleteByNum(L, 2, a);
	cout << a << endl;
	cout << "length:" << length(L) << endl;
}
*/