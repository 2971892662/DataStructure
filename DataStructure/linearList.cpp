/*
线性表：逻辑结构
特点：元素大小一样、有序、数量有限
*/

//引用&测试
int testQuoteA(int n) {
	n = 10000;
	return n;
}

int testQuoteB(int &n) {
	n = 2025;
	return n;
}

/*
测试代码：
void main() {
	int n = -1;
	cout << testQuoteA(n) << endl;
	cout << n << endl;
	printf("% d\n", testQuoteB(n));
	printf("%d\n", n);
}
*/