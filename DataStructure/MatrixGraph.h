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
char firstNeighbor(MGraph M, char t);
char nextNeighbor(MGraph M, char t, char s);
