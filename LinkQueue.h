#pragma once
#include"BiTree.h"
typedef struct LinkNode {  //链式队列结点
	//int data;
	BiTNode* data;
	struct LinkNode* next;
	LinkNode() :data(), next() {} //无参数初始化时调用
}LinkNode;

typedef struct {     //链式队列
	LinkNode* front, * rear;  //队列的队头和队尾指针
}LinkQueue;

/*
InitQueue() //初始化队列(带头结点)
EnQueue() //入队(带头结点)
DeQueue() //出队(带头结点)
IsEmpty() //判断队列是否为空(带头结点)
*/

//初始化队列(带头结点)
void InitQueue(LinkQueue& Q) {
	//队头指针与队尾指针指向一个新结点
	Q.front = Q.rear = new LinkNode;
	//新结点的next指针，指向NULL，防止野指针的情况出现
	Q.front->next = NULL;
}

//新元素入队(带头结点)
void EnQueue(LinkQueue& Q, BiTree x) {


	//将元素x构造为LinkNode结点
	LinkNode* s = new LinkNode;
	s->data = new BiTNode;
	s->data->data = x->data;
	s->data->lchild = x->lchild;
	s->data->rchild = x->rchild;

	/*
	//此时S->data里的所有项目都默认指向NULL,NULL无法接收数据
	s->data->data = x->data;
	s->data->lchild = x->lchild;
	s->data->rchild = x->rchild;
	s->next = NULL;*/


	//新结点插入到rear之后
	Q.rear->next = s;
	//修改表尾指针
	Q.rear = s;
}

//队头元素出队(带头结点)
bool DeQueue(LinkQueue& Q, BiTree& x) {
	if (Q.front == Q.rear) return false;   //队列为空，返回false

	//申请一个临时变量来存储第一个元素的地址
	LinkNode* p = Q.front->next;

	//将第一个元素的值返回给x
	x->data = p->data->data;
	x->lchild = p->data->lchild;
	x->rchild = p->data->rchild;

	//通过修改队头的next 来删除第一个元素
	Q.front->next = p->next;
	//单独考虑只剩下一个结点的情况
	if (Q.rear == p) Q.rear = Q.front;

	return true;
}

//判断队列是否为空(带头结点)
bool IsEmpty(LinkQueue Q) {

	//队头指针与队尾指针重合，代表队列为空
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}