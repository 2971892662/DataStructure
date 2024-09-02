//����
//1.��������
//1.1ֱ�Ӳ�������
#include <iostream>
using namespace std;
void DirectInsertSort(int a[], int len) {
	int temp = 0;
	for (int i = 1; i < len; i++) {
		if (a[i] < a[i - 1]) {
			temp = a[i];
			int j = i - 1;
			for (j; a[j] > temp && j >= 0; j--) {
				a[j + 1] = a[j];
			}
			a[j+1] = temp;	//��j+1��λ�ã���Ϊj����������
		}
	}
}
//1.2�۰��������
void HalfInsertSort(int a[], int len) {
	int temp = 0;
	for (int i = 1; i < len; i++) {
		if (a[i] < a[i - 1]) {
			temp = a[i];
			int low = 0, high = i - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (a[mid] > temp) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			for (int j = i - 1; j>=low; j--) {	//���㷨�ȶ���Ϊ�ٽ�����
				a[j + 1] = a[j];
			}
			a[low] = temp;
		}
	}
}
//1.3ϣ������
void ShellInsertSort(int a[], int len) {
	int temp = 0;
	for (int d = len / 2; d >= 1; d = d / 2) {
		for (int i = 0 + d; i < len; i++) {
			if (a[i] < a[i - d]) {
				temp = a[i];
				int j = i - d;
				for (j; j >= 0 && a[j] > temp; j = j - d) {
					a[j + d] = a[j];
				}
				a[j + d] = temp;
			}
		}
	}
}
//2.��������
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//2.1ð������
void BubbleSwapSort(int a[], int len) {
	for (int i = 0; i < len - 1; i++) {
		bool flag = false;
		for (int j = len - 1; j >i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = true;
			}
		}
		if (flag == false) {
			return;
		}
	}
}
//2.2��������
void QuickSwapSort(int a[], int start,int end) {
	int low = start;
	int high = end;
	int pivot = a[start];
	while (low < high) {
		while (low<high && a[high]>pivot) {
			high--;
		}
		swap(a[low], a[high]);
		//a[low] = a[high];
		while (low < high && a[low] < pivot) {
			low++;
		}
		swap(a[low], a[high]);
		//a[high] = a[low];	//����swap�� ʵ�����
	}
	//a[low] = pivot;	���ʹ��swap��������Ҫ�ⲽ
	if (start <= low - 1) {
		QuickSwapSort(a, start, low - 1);
	}
	if (low + 1 <= end){
		QuickSwapSort(a, low + 1, end);
	}
}
//3.ѡ������
//3.1��ѡ������
void SimpleSelectSort(int a[], int len) {
	for (int i = 0; i < len-1; i++) {
		int min = i;	//һ��ֵ��ѧϰ�ĵط�
		for (int j = i+1; j<len; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
			if (min != i) {
				swap(a[i], a[min]);
			}
		}
	}
}
//3.2������
//len�ǲ�����a[0]��
void HeapAdjust(int a[], int root, int len) {
	a[0] = a[root];
	for (int i = 2 * root; i <= len; i = i * 2) {
		if (i < len && a[i] < a[i + 1]) {
			i++;
		}
		if (a[0] >= a[i]) {
			break;	//����return
		}
		else {
			a[root] = a[i];
			root = i;	//��ִ������һ���������
		}
	}
	a[root] = a[0];
}
void BuildMaxHeap(int a[], int len) {
	for (int i = len / 2; i > 0; i--) {
		HeapAdjust(a, i, len);
	}
}
void HeapSelectSort(int a[], int len) {
	BuildMaxHeap(a, len);
	for (int i = 1; i <= len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = len; i > 1; i--) {
		cout << a[1] << " ";
		swap(a[i], a[1]);
		HeapAdjust(a, 1, i - 1);
	}
	cout << a[1];
}
/*
int main() {
	int s[] = { 0,22,-3,4,15,66,7,1 };
	HeapSelectSort(s,sizeof(s) / sizeof(int)-1);
}
*/