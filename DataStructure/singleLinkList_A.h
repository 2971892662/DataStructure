//������,����ͷ�ڵ�
struct LNode_A {
	int data;
	//C++����struct��������
	LNode_A* next;
	/*
	iΪָ�������jΪ���α���->*���Ǻͱ���������һ��ȽϺ�
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
