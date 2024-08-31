#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TopologicalSort.h"

using namespace std;

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
//		¨J		¨I	 |
//	c<---------------d
//
	TopologicalSort(mg);
}