//不带头节点的单链表
struct LNode_B {
	int data;
	LNode_B* next;
};

bool initLNode_B(LNode_B*& L);
int length(LNode_B* L);
bool isEmpty(LNode_B* L);
LNode_B* getByNum(LNode_B* L, int num);
LNode_B* getByVal(LNode_B* L, int val);
bool insertByNum(LNode_B*& L, int num, int val);
bool deleteByNum(LNode_B*& L, int num, int& val);
