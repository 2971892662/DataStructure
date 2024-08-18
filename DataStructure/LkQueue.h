#include <stdlib.h>
struct LNode {
	int data;
	LNode* next;
};
struct LkQueue {
	LNode* front;
	LNode* rear;
	int length;
};
//带有头结点的链队。添加length变量以方便记录长度。
void initQueue(LkQueue& q);
bool isEmpty(LkQueue q);
bool enqueue(LkQueue& q, int val);
bool dequeue(LkQueue& q, int& val);
bool destroy(LkQueue& q);
