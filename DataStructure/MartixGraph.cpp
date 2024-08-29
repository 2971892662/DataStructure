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
//图的广度优先遍历
//图的深度优先遍历
//图的拓扑排序