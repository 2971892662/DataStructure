#include "sqStack.h"
//顺序栈
/*
关键在于s.top所赋初值为-1则入栈先++再写入
*/
void initStack(sqStack &s) {
	s.top = -1;
}
bool isEmpty(sqStack& s) {
	return (s.top == -1);
}
bool push(sqStack& s,int val) {
	if (s.top >= MaxSize - 1) {
		return false;
	}
	s.top++;
	s.data[s.top] = val;
	return true;
}
bool pop(sqStack& s, int& val) {
	if (s.top <= -1) {
		return false;
	}
	val = s.data[s.top];
	s.top--;
	return true;
}
bool getTop(sqStack& s, int& val) {
	if (s.top <= -1) {
		return -1;
	}
	val= s.data[s.top];
	return true;
}
bool destroy() {
	return true;
}

/*
int main() {
	sqStack s;
	initStack(s);
	int i;
	cin >> i;
	while (i!=-1) {
		push(s, i);
		cin >> i;
	}
	while (!isEmpty(s)) {
		getTop(s, i);
		cout << i << endl;
		pop(s, i);
	}
}
*/