#include "sqQueue.h"
void initQueue(sqQueue& q) {
	q.front = 0;
	q.rear = 0;
}
bool destroy(sqQueue& q) {
	return true;
}
bool isFull(sqQueue& q) {
	if ((q.rear + 1+MaxSize)%MaxSize == q.front) {
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty(sqQueue& q) {
	if (q.rear == q.front) {
		return true;
	}
	else {
		return false;
	}
}
bool enqueue(sqQueue& q,int val) {
	if (isFull(q)) {
		return false;
	}
	q.data[q.rear] = val;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
int length(sqQueue& q) {
	return (q.rear - q.front + MaxSize) % MaxSize;
}
bool dequeue(sqQueue& q, int& val) {
	if (isEmpty(q)) {
		return false;
	}
	val = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

/*
int main() {
	sqQueue q;
	initQueue(q);
	int i;
	cin >> i;
	while (i != -1) {
		enqueue(q, i);
		cin >> i;
	}
	cout << "length:" << length(q)<<endl;
	while (!isEmpty(q)) {
		dequeue(q, i);
		cout << i << endl;
	}
}
*/