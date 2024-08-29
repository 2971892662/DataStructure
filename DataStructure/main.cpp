#include <iostream>
#include <stdio.h>
#include <string.h>
#include "MatrixGraph.h"

using namespace std;

int main() {
	MGraph mg;
	mg.vertex[0] = 'a';
	mg.vertex[1] = 'b';
	mg.vertex[2] = 'c';
	mg.vertex[3] = 'd';
	mg.vertex[4] = 'e';
/*以下赋值方式是不对的
	mg.edge = { {0,1,1,0,1},
		{1,0,0,1,1},
		{1,0,0,1,1},
		{0,1,1,0,1},
		{1,1,1,1,0} };
*/
	mg.arcnum = 8;
	mg.vexnum = 5;
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
/*
	a---------------b
	|	\		/	|
	|		e		|
	|	/		\	|
	c---------------d
*/
	for (char s = firstNeighbor(mg, 'e'); s != '#'; s = nextNeighbor(mg, 'e', s)) {
		cout << s << "	";
	}
}