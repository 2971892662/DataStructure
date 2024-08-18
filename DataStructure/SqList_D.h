//采用动态分配实现顺序表
struct SqList_D {
	int* data;
	int length;
	int maxSize;
};

void initSqList_D(SqList_D& L);
void increaseSqList_D(SqList_D& L);
bool SqList_DInsert(SqList_D& L, int i, int value);
bool SqList_DDelete(SqList_D& L, int i, int& value);
int getNum(SqList_D L, int i);
int locateNum(SqList_D L, int value);
