/*
���Ա��߼��ṹ
�ص㣺Ԫ�ش�Сһ����������������
*/

//����&����
int testQuoteA(int n) {
	n = 10000;
	return n;
}

int testQuoteB(int &n) {
	n = 2025;
	return n;
}

/*
���Դ��룺
void main() {
	int n = -1;
	cout << testQuoteA(n) << endl;
	cout << n << endl;
	printf("% d\n", testQuoteB(n));
	printf("%d\n", n);
}
*/