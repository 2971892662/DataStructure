#define MaxSize 50
struct sqQueue {
	int data[MaxSize];
	int front, rear;
};
//˳��洢�ṹ��ѭ������,����һ���洢��Ԫ������
void initQueue(sqQueue& q);
bool destroy(sqQueue& q);
bool isFull(sqQueue& q);
bool isEmpty(sqQueue& q);
bool enqueue(sqQueue& q, int val);
int length(sqQueue& q);
bool dequeue(sqQueue& q, int& val);
//һ������ĺ�������˳�򣺳�ʼ��->�������п�->��Ӻͳ���->���٣����������Ϊ�����ó�����ʵ�֣�