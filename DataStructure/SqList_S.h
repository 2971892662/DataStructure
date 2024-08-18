#define MaxSize 100

//采用静态分配实现顺序表
struct SqList_S {
	int data[MaxSize];
	int length;
};

void initSqList_S(SqList_S & L);
bool SqList_SInsert(SqList_S& L, int i, int value);
bool SqList_SDelete(SqList_S& L, int i, int& value);
int getNum(SqList_S L, int i);
int locateNum(SqList_S L, int value);
