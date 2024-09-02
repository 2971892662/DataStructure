//排序
//1.插入排序
//1.1直接插入排序
void DirectInsertSort(int a[], int len) {
	int temp = 0;
	for (int i = 1; i < len; i++) {
		if (a[i] < a[i - 1]) {
			temp = a[i];
			int j = i - 1;
			for (j; a[j] > temp && j >= 0; j--) {
				a[j + 1] = a[j];
			}
			a[j+1] = temp;	//是j+1的位置，因为j不满足条件
		}
	}
}
//1.2折半插入排序
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
			for (int j = i - 1; j>=low; j--) {	//以算法稳定性为临界条件
				a[j + 1] = a[j];
			}
			a[low] = temp;
		}
	}
}
//1.3希尔排序
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



