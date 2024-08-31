//Õÿ∆À≈≈–Ú
#include <stdlib.h>
#include <iostream>
#define MaxSize 20
using namespace std;
struct DirectedGraph {
	char vertex[MaxSize];
	int vexnum;
	int edge[MaxSize][MaxSize];
	int edgenum;
}; 
struct CharStack {
	char data[MaxSize];
	int top;
};
int* getIndegree(DirectedGraph M);
int getIndex(DirectedGraph M, char a);
void initStack(CharStack& s);
bool isEmpty(CharStack s);
bool isFull(CharStack s);
void push(CharStack& s, char a);
void pop(CharStack& s, char& a);
bool TopologicalSort(DirectedGraph M);
