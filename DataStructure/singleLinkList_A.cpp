#include <stdlib.h>
#include "singleLinkList_A.h"

//带头节点的单链表初始化
//初始化需要传递的参数是：指针的引用
bool initSingleLinkList(LNode_A* &L) {
	L = (LNode_A*)malloc(sizeof(LNode_A*));
	L->data = -1;
	L->next = NULL;
	return true;
}

//判空 
bool isEmpty(LNode_A* L) {
	return (L->next == NULL);
}

//求表长
int length(LNode_A* L) {
	int i = 0;
	LNode_A* p = L;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//按序号查找
LNode_A* getByNum(LNode_A* L, int i) {
	if (i < 1) {
		return NULL;
	}
	LNode_A* p = L;
	int j = 0;
	while (p != NULL && j < i) {	//判空和序号一起判断
		p = p->next;
		j++;
	}
	return p;
}

//按值查找
LNode_A* getByVal(LNode_A* L, int val) {
	LNode_A* p = L->next;
	while (p != NULL && p->data != val) {
		p = p->next;
	}
	/*
	* 可选，应为没找到时自然也会p=NULL
	if (p == NULL) {
		return NULL;
	}
	*/
	return p;
}

//指定位序处插入
bool insertByNum(LNode_A* L, int num, int val) {
	if (num < 1) {
		return false;
	}
	LNode_A* p = L;
	int i = 0;
	while (p != NULL && i < num - 1) {	//即i=num-1时停止循环
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

//按指定位序删除
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