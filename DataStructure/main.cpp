#include <iostream>
#include <stdio.h>
#include <string.h>
#include "BSTSearch.h"
using namespace std;

int main() {
	int a[] = { 11,2,13,4,-2 };
	BSTNode* res = createBSTree(a, 5);
	preBSTTraverse(res);
}