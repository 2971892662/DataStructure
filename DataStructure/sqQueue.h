#define MaxSize 50
struct sqQueue {
	int data[MaxSize];
	int front, rear;
};
//顺序存储结构的循环队列,牺牲一个存储单元来判满
void initQueue(sqQueue& q);
bool destroy(sqQueue& q);
bool isFull(sqQueue& q);
bool isEmpty(sqQueue& q);
bool enqueue(sqQueue& q, int val);
int length(sqQueue& q);
bool dequeue(sqQueue& q, int& val);
//一个不错的函数声明顺序：初始化->判满与判空->入队和出队->销毁（放在最后，因为可以用出队来实现）