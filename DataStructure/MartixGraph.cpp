#include "MatrixGraph.h"

//��������������firstNeighbor��nextneighbor
char firstNeighbor(MGraph M,char t) {
	int i = 0;
	while (M.vertex[i] != t) {
		i++;
	}
	int j = 0;
	while (M.edge[i][j] != 1 && j < M.vexnum) {	//�ж�Խ��
		j++;
	}
	if (j == M.vexnum) {
		return '#';	//#��ǿգ��ޣ�
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
//ͼ�Ĺ�����ȱ���
//ͼ��������ȱ���
//ͼ����������