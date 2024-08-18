#define MaxSize 50
struct sqStack {
	int data[MaxSize];
	int top;
}; 
void initStack(sqStack& s);
bool isEmpty(sqStack& s);
bool push(sqStack& s, int val);
bool pop(sqStack& s, int& val);
bool getTop(sqStack& s, int& val);
bool destroy();
