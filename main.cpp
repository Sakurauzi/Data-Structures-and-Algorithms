#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
//#include "BiTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//��������㷨
void LevelOrder(BiTree T) {
	//���帨������Q
	LinkQueue Q;
	//��ʼ����������
	InitQueue(Q);

	//��ʼ��һ�������ָ��
	//ԭ����ͬ��Ҳ��û�и���ʼֵ������pָ��NULL��DeQueue�޷���NULLд������
	//BiTree p;

	EnQueue(Q, T);

	while (!IsEmpty(Q)) {
		BiTree p = new BiTNode;
		DeQueue(Q, p);

		cout << p->data << endl;

		if (p->lchild != NULL) EnQueue(Q, p->lchild);

		if (p->rchild != NULL) EnQueue(Q, p->rchild);
	}
}

//��������㷨



//��������㷨



//���������㷨



int main(int argc, char** argv) {
	/*
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';

	BiTree root = new BiTNode(a);
	root->lchild = new BiTNode(b);
	root->rchild = new BiTNode(c);
	root->rchild->lchild = new BiTNode(d);
	root->rchild->lchild->rchild = new BiTNode(e);
	root->rchild->rchild = new BiTNode(f);

	LevelOrder(root);*/
	
	LinkStack S;
	InitStack(S);
	cout << S.top->data << endl;
	cout << S.top->next << endl;

	Push(S, 'a');
	cout << S.top->data << endl;
	cout << S.top->next << endl;

	return 0;
}