#include <stdlib.h>
struct LNode {
	int data;
	LNode* next;
};
//没有头结点的链栈
void initStack(LNode*& s);
bool isEmpty(LNode*& s);
bool push(LNode*& s, int val);
bool pop(LNode*& s, int& val);
bool destroy(LNode*& s);
bool getTop(LNode*& s, int& val);
