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
//����ͷ�������ӡ����length�����Է����¼���ȡ�
void initQueue(LkQueue& q);
bool isEmpty(LkQueue q);
bool enqueue(LkQueue& q, int val);
bool dequeue(LkQueue& q, int& val);
bool destroy(LkQueue& q);
