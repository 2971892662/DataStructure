#include "lqStack.h"
/*
链栈（无头结点）
入栈要对空栈、出栈要对只有一个数据的情况进行特殊处理
*/
void initStack(LNode*& s) {
	s= NULL;
}
bool isEmpty(LNode*& s) {
	if (s == NULL) {
		return true;
	}
	else {
		return false;
	}
}
bool push(LNode*& s, int val) {
	LNode* n = (LNode*)malloc(sizeof(LNode));
	n->data = val;
	if (s == NULL) {
		n->next = NULL;
		s = n;
		return true;
	}
	n->next = s;
	s = n;
	return true;
}
bool pop(LNode*& s, int& val) {
	if (s == NULL) {
		return false;
	}
	if (s->next == NULL) {
		val = s->data;
		LNode* p = s;
		free(p);
		s = NULL;
		return true;
	}
	val = s->data;
	LNode* p = s;
	s = p->next;
	free(p);
	return true;
}
//不带头结点的删除
bool destroy(LNode*& s) {
	while (s != NULL) {
		LNode* p = s;
		s = s->next;
		free(p);
	}
	return true;
}
bool getTop(LNode*& s, int& val) {
	if (s == NULL) {
		return false;
	}
	val = s->data;
	return true;
}

/*
int main() {
	LNode* s;
	initStack(s);
	int i;
	cin >> i;
	while (i != -1) {
		push(s, i);
		cin >> i;
	}
	while (!isEmpty(s)) {
		getTop(s, i);
		cout << i << endl;
		pop(s, i);
	}
}
*/