#pragma once
//��ջ���
typedef struct LinkStackNode {
	char data;
	struct LinkStackNode* next;
}LinkStackNode;

//��ջ
typedef struct LinkStack {
	LinkStackNode* top;
}LinkStack;

//��ʼ����ջ(����ͷ���)
void InitStack(LinkStack& S) {
	//topָ��һ��ͷ���
	S.top = new LinkStackNode;
	//Ϊ�˷�ֹҰָ���������֣���Ҫ��data��char��ֵ
	S.top->data = ' ';
	S.top->next = NULL;
}

//��ջ
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