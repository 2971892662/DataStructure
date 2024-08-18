int func2(int x) {
	int m, n;
	m = x + 1;
	n = x + 2;
	return 1;
}
int func1(int a, int b) {
	int x = a + b;
	func2(x);
	x = x + 10086;
	return 1;
}
/*
int main() {
	int a = 1, b = 2, c = 3;
	func1(a, b);
	c = a + b;
}
研究堆栈调用
可以看到最底下是[外部代码]
*/