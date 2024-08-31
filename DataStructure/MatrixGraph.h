#include <iostream>

using namespace std;
//ʹ���ڽӾ���洢ͼ
#define MaxSize 20
struct MGraph {
	char vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vexnum, arcnum;
};
//���ж�������ʹchar���ͣ����Ǳ߱�һ����int����
struct sqQueueC {
	char data[MaxSize];
	int front, rear;
};
char firstNeighbor(MGraph M, char t);
char nextNeighbor(MGraph M, char t, char s);
void initQueue(sqQueueC& q);
bool destroy(sqQueueC& q);
bool isFull(sqQueueC& q);
bool isEmpty(sqQueueC& q);
bool enqueue(sqQueueC& q, char val);
int length(sqQueueC& q);
bool dequeue(sqQueueC& q, char& val);
void BFS(MGraph M, char root, int* visited);
void BFSTraverse(MGraph M, char root);
//����:fatal error LNK1169: �ҵ�һ���������ض���ķ���	sqQueueC
void DFS(MGraph M, char root, int* visited);
void DFSTraverse(MGraph M, char root);