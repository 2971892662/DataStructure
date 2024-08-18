#include "LkQueue.h"
void initQueue(LkQueue& q) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	q.front = p;
	q.rear = p;
	q.length = 0;
}
bool isEmpty(LkQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	else {
		return false;
	}
}
bool enqueue(LkQueue& q,int val) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = val;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
	q.length++;
	return true;
}
bool dequeue(LkQueue& q, int& val) {
	if (isEmpty(q)) {
		return false;
	}
	LNode* t = q.front->next;
	val = t->data;
	q.front->next = t->next;
	if (t->next == NULL) {
		q.rear = q.front;
	}
	free(t);
	q.length--;
	return true;
}
bool destroy(LkQueue& q) {
	int i;
	while (!isEmpty(q)) {
		dequeue(q, i);
	}
	free(q.front);
	return true;
}

/*
int main() {
	LkQueue q;
	initQueue(q);
	int i;
	cin >> i;
	while (i != -1) {
		enqueue(q, i);
		cin >> i;
	}
	cout << "length:" << q.length << endl;
	while (!isEmpty(q)) {
		dequeue(q, i);
		cout << i<<endl;
	}
	destroy(q);
	cout << "length:" << q.length << endl;
}
*/