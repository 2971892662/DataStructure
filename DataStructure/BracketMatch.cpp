#define MaxSize 50
struct SqStack {
	char data[MaxSize];
	int top;
};
void initStack(SqStack& s) {
	s.top = -1;
}
bool isEmpty(SqStack& s) {
	return s.top == -1;
}
bool isFull(SqStack& s) {
	return s.top == MaxSize-1;
}
bool push(SqStack& s,char val) {
	if (isFull(s)) {
		return false;
	}
	s.top++;
	s.data[s.top] = val;
	return true;
}
bool pop(SqStack& s, char &val) {
	if (isEmpty(s)) {
		return false;
	}
	val = s.data[s.top];
	s.top--;
	return true;
}
//char������Ϊ��������
bool bracketMatch(char b[], int len) {
	SqStack s;
	initStack(s);
	char a='[';
	for (int i = 0; i <= len - 1; i++) {
		if (b[i] == '(' || b[i] == '[' || b[i] == '{') {
			push(s, b[i]);
			continue;
		}
		if (isEmpty(s)) {
			return false;
		}
		switch (b[i]) {
		case ')':
			pop(s, a);
			if (a == '(') {
				break;
			}
			else {
				return false;
			}
		case ']':
			pop(s, a);
			if (a == '[') {
				break;
			}
			else {
				return false;
		case '}':
			pop(s, a);
			if (a == '{') {
				break;
			}
			else {
				return false;
			}
			}
		}
	}
	return isEmpty(s);
}

/*
int main() {
	char a[9] = "(([])){}";
	cout<<bracketMatch(a, 8)<<endl;
}
*/
/*
char����ĳ�ʼ����
1.ֱ�����ַ�����ֵ�������ȶ����ٸ�ֵ
���ô��ַ�ʽ����Ҫһ���ռ�洢'\0'
2.���������ַ������ֵ����char a[2]={'a','b'}
���ַ�ʽû��'\0'
ʹ��cout���ʱ��ʹ�����������ɣ���cout<<a,���������ab������ү0h������Ϊ�ַ�������û��'\0'�����һֱ
���ֱ������'\0'Ϊֹ��
*/
/*
�ַ��������룺
int main(){
	char ch[20];
	cin >> ch;
	cout << ch;

	return 0;
}
���룺abc def xyz
�����abc
*/
/*
�ַ����鳤�ȣ�
char str[20]="0123456789";
int   a=strlen(str); /*a=10;strlen �����ַ����ĳ��ȣ���\0'Ϊ�ַ���������ǡ�
int   b=sizeof(str); /*b=20;sizeof ��������Ƿ��������str[20] ��ռ���ڴ�ռ�Ĵ�С����������洢������Ӱ��
str.length()��str.size()��������string�����ĳ�Ա����
char ss[] = "0123456789";���Ϊ11
����Ƚ���sizeof()��strlen() ��һ�ֺ��������ڼ����ַ����ĳ��ȣ���ֻ�ܼ����ַ���������\0����Ϊ��ֹ�������ص�
���ȴ�С��������\0�������� strlen �Ľ�������е�ʱ��ų���(���Ǳ�������ֵ)
int main() {
	char a[20];
	cin >> a;
	cout << strlen(a)<<endl; �������Ԥ��
}
*/