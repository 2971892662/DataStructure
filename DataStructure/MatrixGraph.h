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
char firstNeighbor(MGraph M, char t);
char nextNeighbor(MGraph M, char t, char s);
