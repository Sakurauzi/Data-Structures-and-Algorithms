#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
//#include "BiTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//层序遍历算法
void LevelOrder(BiTree T) {
	//定义辅助队列Q
	LinkQueue Q;
	//初始化辅助队列
	InitQueue(Q);

	//初始化一个树结点指针
	//原方法同样也是没有赋初始值，导致p指向NULL，DeQueue无法往NULL写入数据
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

//先序遍历算法



//中序遍历算法



//后续遍历算法



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