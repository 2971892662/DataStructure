#include <iostream>

using namespace std;
//使用邻接矩阵存储图
#define MaxSize 20
struct MGraph {
	char vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vexnum, arcnum;
};
//其中顶点表可以使char类型，但是边表一定是int类型
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
//错误:fatal error LNK1169: 找到一个或多个多重定义的符号	sqQueueC
void DFS(MGraph M, char root, int* visited);
void DFSTraverse(MGraph M, char root);