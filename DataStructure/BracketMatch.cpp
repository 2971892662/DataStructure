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
//char数组作为参数传递
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
char数组的初始化：
1.直接用字符串赋值。不能先定义再赋值
采用此种方式会需要一个空间存储'\0'
2.对数组中字符逐个赋值，如char a[2]={'a','b'}
此种方式没有'\0'
使用cout输出时，使用数组名即可，如cout<<a,但会输出“ab烫烫烫爷0h”，因为字符数组中没有'\0'，便会一直
输出直到遇到'\0'为止。
*/
/*
字符串的输入：
int main(){
	char ch[20];
	cin >> ch;
	cout << ch;

	return 0;
}
输入：abc def xyz
输出：abc
*/
/*
字符数组长度：
char str[20]="0123456789";
int   a=strlen(str); /*a=10;strlen 计算字符串的长度，以\0'为字符串结束标记。
int   b=sizeof(str); /*b=20;sizeof 计算的则是分配的数组str[20] 所占的内存空间的大小，不受里面存储的内容影响
str.length()和str.size()是用于求string类对象的成员函数
char ss[] = "0123456789";结果为11
而相比较于sizeof()，strlen() 是一种函数，用于计算字符串的长度，（只能计算字符串），‘\0’作为终止符，返回的
长度大小不包括’\0’，并且 strlen 的结果是运行的时候才出来(不是编译期求值)
int main() {
	char a[20];
	cin >> a;
	cout << strlen(a)<<endl; 结果满足预期
}
*/