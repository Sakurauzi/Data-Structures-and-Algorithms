#pragma once
//链栈结点
typedef struct LinkStackNode {
	char data;
	struct LinkStackNode* next;
}LinkStackNode;

//链栈
typedef struct LinkStack {
	LinkStackNode* top;
}LinkStack;

//初始化链栈(加上头结点)
void InitStack(LinkStack& S) {
	//top指向一个头结点
	S.top = new LinkStackNode;
	//为了防止野指针的情况出现，需要给data和char赋值
	S.top->data = ' ';
	S.top->next = NULL;
}

//进栈
bool Push(LinkStack& S, char x) {
	if (S.top == NULL)
		return false;

	LinkStackNode* p = new LinkStackNode;
	p->data = x;
	p->next = NULL;

	S.top->next = p;
	S.top = p;
	return true;
}