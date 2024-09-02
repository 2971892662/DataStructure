//����
//1.��������
//1.1ֱ�Ӳ�������
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

