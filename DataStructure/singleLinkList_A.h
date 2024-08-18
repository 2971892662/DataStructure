//单链表,带有头节点
struct LNode_A {
	int data;
	//C++风格的struct变量声明
	LNode_A* next;
	/*
	i为指针变量，j为整形变量->*还是和变量名放在一起比较好
	int* i, j;
	i = 100;
	j = 100;
	*/
};

bool initSingleLinkList(LNode_A* &L);
int length(LNode_A* L);
LNode_A* getByNum(LNode_A* L, int i);
LNode_A* getByVal(LNode_A* L, int val);
bool insertByNum(LNode_A* L, int num, int val);
bool deleteByNum(LNode_A* L, int num, int& val);
