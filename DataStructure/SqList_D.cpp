#include <stdlib.h>
#include "SqList_D.h"

void initSqList_D(SqList_D &L) {
	L.data = (int*)malloc(sizeof(int) * 10);
	L.length = 0;
	L.maxSize = 10;
}

//增加顺序表长度
void increaseSqList_D(SqList_D &L) {
	int* p = (int*)malloc(sizeof(int) * (L.maxSize<<1));
	for (int i = 0; i < L.length; i++) {
		p[i] = L.data[i];
	}
	int* t = L.data;
	L.data = p;
	free(t);
	L.maxSize = L.maxSize<<1;
}

bool SqList_DInsert(SqList_D& L, int i, int value) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	for (int j = L.length; j >= i - 1 + 1; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = value;
	L.length++;
	return true;
}

bool SqList_DDelete(SqList_D& L, int i, int& value) {
	if (i<1 || i>L.length) {
		return false;
	}
	value = L.data[i - 1];
	for (int j = i; j<L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int getNum(SqList_D L, int i) {
	if (i<1 || i>L.length) {
		return -1;
	}
	return L.data[i - 1];
}

int locateNum(SqList_D L, int value) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == value) {
			return i + 1;
		}
	}
	return -1;
}