//并查集
#include <stdlib.h>
#define SIZE 10
struct Union {
	int data[SIZE];
};
void initUnion(Union& un) {
	for (int i = 0; i < SIZE; i++) {
		un.data[i] = -1;
	}
}
//find找到根节点
int findUnpress(Union un, int s) {
	while (un.data[s] >= 0) {
		s = un.data[s];
	}
	return s;
}
//矮树合并到高树上
void join(Union un,int a, int b) {
	if (a == b) {
		return;
	}
	int root1=un.data[findUnpress(un, a)];
	int root2=un.data[findUnpress(un, b)];
	if (root1 <= root2) {
		root1 = root1 + root2;
		un.data[findUnpress(un, b)] = findUnpress(un, a);
	}
	else {
		root2 = root2 + root1;
		un.data[findUnpress(un, a)] = findUnpress(un, b);
	}
}
//压缩路径查找
int findPress(Union un, int s) {
	int i = s;
	int root;
	while (un.data[s] >= 0) {
		s = un.data[s];
	}
	root = s;
	while (un.data[i] >= 0) {
		int j = un.data[i];
		un.data[i] = root;
		i = j;
	}
	return root;
}