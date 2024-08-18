#include "SqList_S.h"

void initSqList_S(SqList_S &L) {
	//��0��ʡ��
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

bool SqList_SInsert(SqList_S& L, int i, int value) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	for (int j = L.length; j>=i-1+1; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = value;
	L.length++;
	return true;
}

bool SqList_SDelete(SqList_S& L, int i, int& value) {
	if (i<1 || i>L.length) {
		return false;
	}
	value = L.data[i - 1];
	//ʼ����j��j-1�Ĺ�ϵ�����ʹ��j+1��Ҫ���⿼�Ǳ�βλ��
	for (int j = i;j<L.length;j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int getNum(SqList_S L, int i) {
	if (i<1 || i>L.length) {
		return -1;
	}
	return L.data[i - 1];
}

int locateNum(SqList_S L, int value) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == value) {
			return i + 1;
		}
	}
	return -1;
}

/*
void main() {
	SqList_S L;
	initSqList_S(L);
	SqList_SInsert(L, 1, 1);
	SqList_SInsert(L, 2, 2);
	SqList_SInsert(L, 2, 3);
	int e = -1;
	cout << "��2�Ŵ�ţ�" << getNum(L, 2) << endl;
	cout << "3�����λ��" << locateNum(L, 3) << endl;
	while(SqList_SDelete(L, 1, e)) {
		cout << e << endl;
	}
}
*/