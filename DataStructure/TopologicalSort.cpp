#include "TopologicalSort.h"

int* getIndegree(DirectedGraph M) {
	int num = M.vexnum;
	int* indegree = (int*)malloc(sizeof(int)*num);
	int count = 0;
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < num; i++) {
			if (M.edge[i][j] == 1) {
				count++;
			}
		}
		indegree[j] = count;
		count = 0;
	}
	return indegree;
}
int getIndex(DirectedGraph M, char a) {
	int i = 0;
	while (M.vertex[i] != a) {
		i++;
	}
	return i;
}
void initStack(CharStack& s) {
	s.top = 0;
}
bool isEmpty(CharStack s) {
	if (s.top == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool isFull(CharStack s) {
	if (s.top == MaxSize) {
		return true;
	}
	else {
		return false;
	}
}
void push(CharStack& s, char a) {
	if (!isFull(s)) {
		s.data[s.top] = a;
		s.top++;
	}
}
void pop(CharStack& s, char& a) {
	if (isEmpty(s)) {
		return;
	}
	s.top--;
	a = s.data[s.top];
}
bool TopologicalSort(DirectedGraph M) {
	int* indegree = getIndegree(M);
	CharStack sta;
	initStack(sta);
	int count = 0;
	for (int i = 0; i < M.vexnum; i++) {
		if (indegree[i] == 0) {
			push(sta, M.vertex[i]);
		}
	}
	while (!isEmpty(sta)) {
		char a;
		pop(sta, a);
		count++;
		cout << a << " ";
		for (int i = 0; i < M.vexnum; i++) {
			if (M.edge[getIndex(M, a)][i] == 1) {
				indegree[i]--;
				if (indegree[i] == 0) {
					push(sta, M.vertex[i]);
				}
			}
		}
	}
	if (count < M.vexnum) {
		cout <<endl<< "有环！";
		return false;
	}
	else {
		cout << endl << "无环！";
		return true;
	}
}
/*
int main() {
	DirectedGraph mg;
	mg.vertex[0] = 'a';
	mg.vertex[1] = 'b';
	mg.vertex[2] = 'c';
	mg.vertex[3] = 'd';
	mg.vertex[4] = 'e';
	mg.vertex[5] = 'z';
	mg.edgenum = 5;
	mg.vexnum = 6;
	for (int i = 0; i < mg.vexnum; i++) {
		for (int j = 0; j < mg.vexnum; j++) {
			mg.edge[i][j] = 0;
		}
	}
	mg.edge[0][1] = 1;
	mg.edge[1][2] = 1;
	mg.edge[2][3] = 1;
	mg.edge[2][4] = 1;
	mg.edge[3][4] = 1;
	//mg.edge[4][0] = 1;
//
//	a--------------->b
//					 |
//			e		 |		z
//		↗		↖	 |
//	c<---------------d
//
	TopologicalSort(mg);
}
*/

