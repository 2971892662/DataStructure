#include "MatrixGraph.h"

//两个基本操作：firstNeighbor和nextneighbor
char firstNeighbor(MGraph M,char t) {
	int i = 0;
	while (M.vertex[i] != t) {
		i++;
	}
	int j = 0;
	while (M.edge[i][j] != 1 && j < M.vexnum) {	//判断越界
		j++;
	}
	if (j == M.vexnum) {
		return '#';	//#标记空（无）
	}
	return M.vertex[j];
}
char nextNeighbor(MGraph M, char t, char s) {
	int i = 0;
	while (M.vertex[i] != t) {
		i++;
	}
	int j = 0;
	while (M.vertex[j] != s) {
		j++;
	}
	int k = j + 1;
	while (M.edge[i][k] != 1&&k<M.vexnum) {
		k++;
	}
	if (k == M.vexnum) {
		return '#';
	}
	return M.vertex[k];
}
int getIndex(MGraph M, char a) {
	int i = 0;
	while (M.vertex[i] != a) {
		i++;
	}
	return i;
}


void initQueue(sqQueueC& q) {
	q.front = 0;
	q.rear = 0;
}
bool destroy(sqQueueC& q) {
	return true;
}
bool isFull(sqQueueC& q) {
	if ((q.rear + 1 + MaxSize) % MaxSize == q.front) {
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty(sqQueueC& q) {
	if (q.rear == q.front) {
		return true;
	}
	else {
		return false;
	}
}
bool enqueue(sqQueueC& q, char val) {
	if (isFull(q)) {
		return false;
	}
	q.data[q.rear] = val;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
int length(sqQueueC& q) {
	return (q.rear - q.front + MaxSize) % MaxSize;
}
bool dequeue(sqQueueC& q, char& val) {
	if (isEmpty(q)) {
		return false;
	}
	val = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}
//图的广度优先遍历
void BFS(MGraph M, char root,int* visited) {
	sqQueueC que;
	initQueue(que);
	enqueue(que, root);
	char visit;
	char t;
	//int visited[vexnum] = -1; 表达式必须是常量值
	visited[getIndex(M, root)] = 1;
	//用visited标记已遍历的元素
	while (!isEmpty(que)) {
		dequeue(que, visit);
		cout << visit << " ";
		for (t = firstNeighbor(M, visit); t != '#'; t = nextNeighbor(M, visit, t)) {
			if (visited[getIndex(M, t)] == -1) {
				enqueue(que, t);
				visited[getIndex(M, t)] = 1;
			}
		}
	}
}
void BFSTraverse(MGraph M, char root) {
	int visited[MaxSize];
	for (int i = 0; i < M.vexnum; i++) {
		visited[i] = -1;
	}
	BFS(M, root,visited);
	for (int i = 0; i < M.vexnum; i++) {
		if (visited[i] == -1) {
			BFS(M, M.vertex[i],visited);
		}
	}
}
//图的深度优先遍历
void DFS(MGraph M, char root,int* visited) {
	cout << root<<" ";
	visited[getIndex(M, root)] = 1;
	int i = getIndex(M, root);
	for (int j = 0; j < M.vexnum; j++) {
		if (M.edge[i][j] == 1 && visited[j] == -1) {
			DFS(M, M.vertex[j], visited);	//使用递归调用，不需要用栈
		}
	}
}
void DFSTraverse(MGraph M, char root) {
	int visited[MaxSize] ;
	for (int i = 0; i < MaxSize; i++) {
		visited[i] = -1;
	}
	//这样既能指定遍历的起始点，又能遍历其他连通分量
	DFS(M, root, visited);
	for (int i = 0; i < M.vexnum; i++) {
		if (visited[i] == -1) {
			DFS(M, M.vertex[i], visited);
		}
	}
}
/*
int main() {
	MGraph mg;
	mg.vertex[0] = 'a';
	mg.vertex[1] = 'b';
	mg.vertex[2] = 'c';
	mg.vertex[3] = 'd';
	mg.vertex[4] = 'e';
	mg.vertex[5] = 'z';
//以下赋值方式是不对的
//	mg.edge = { {0,1,1,0,1},
//		{1,0,0,1,1},
//		{1,0,0,1,1},
//		{0,1,1,0,1},
//		{1,1,1,1,0} };
mg.arcnum = 8;
mg.vexnum = 6;
for (int i = 0; i < mg.vexnum; i++) {
	for (int j = 0; j < mg.vexnum; j++) {
		mg.edge[i][j] = 0;
	}
}
mg.edge[0][1] = 1;
mg.edge[0][2] = 1;
mg.edge[0][4] = 1;
mg.edge[1][0] = 1;
mg.edge[1][3] = 1;
mg.edge[1][4] = 1;
mg.edge[2][0] = 1;
mg.edge[2][3] = 1;
mg.edge[2][4] = 1;
mg.edge[3][1] = 1;
mg.edge[3][2] = 1;
mg.edge[3][4] = 1;
mg.edge[4][0] = 1;
mg.edge[4][1] = 1;
mg.edge[4][2] = 1;
mg.edge[4][3] = 1;
//
//	a---------------b
//	|	\		/	|
//	|		e		|		z
//	c---------------d
//
BFSTraverse(mg, 'c');
cout << endl;
DFSTraverse(mg, 'b');
}
*/