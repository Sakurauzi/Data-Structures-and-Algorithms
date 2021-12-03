#pragma once
#include"BiTree.h"
typedef struct LinkNode {  //��ʽ���н��
	//int data;
	BiTNode* data;
	struct LinkNode* next;
	LinkNode() :data(), next() {} //�޲�����ʼ��ʱ����
}LinkNode;

typedef struct {     //��ʽ����
	LinkNode* front, * rear;  //���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

/*
InitQueue() //��ʼ������(��ͷ���)
EnQueue() //���(��ͷ���)
DeQueue() //����(��ͷ���)
IsEmpty() //�ж϶����Ƿ�Ϊ��(��ͷ���)
*/

//��ʼ������(��ͷ���)
void InitQueue(LinkQueue& Q) {
	//��ͷָ�����βָ��ָ��һ���½��
	Q.front = Q.rear = new LinkNode;
	//�½���nextָ�룬ָ��NULL����ֹҰָ����������
	Q.front->next = NULL;
}

//��Ԫ�����(��ͷ���)
void EnQueue(LinkQueue& Q, BiTree x) {


	//��Ԫ��x����ΪLinkNode���
	LinkNode* s = new LinkNode;
	s->data = new BiTNode;
	s->data->data = x->data;
	s->data->lchild = x->lchild;
	s->data->rchild = x->rchild;

	/*
	//��ʱS->data���������Ŀ��Ĭ��ָ��NULL,NULL�޷���������
	s->data->data = x->data;
	s->data->lchild = x->lchild;
	s->data->rchild = x->rchild;
	s->next = NULL;*/


	//�½����뵽rear֮��
	Q.rear->next = s;
	//�޸ı�βָ��
	Q.rear = s;
}

//��ͷԪ�س���(��ͷ���)
bool DeQueue(LinkQueue& Q, BiTree& x) {
	if (Q.front == Q.rear) return false;   //����Ϊ�գ�����false

	//����һ����ʱ�������洢��һ��Ԫ�صĵ�ַ
	LinkNode* p = Q.front->next;

	//����һ��Ԫ�ص�ֵ���ظ�x
	x->data = p->data->data;
	x->lchild = p->data->lchild;
	x->rchild = p->data->rchild;

	//ͨ���޸Ķ�ͷ��next ��ɾ����һ��Ԫ��
	Q.front->next = p->next;
	//��������ֻʣ��һ���������
	if (Q.rear == p) Q.rear = Q.front;

	return true;
}

//�ж϶����Ƿ�Ϊ��(��ͷ���)
bool IsEmpty(LinkQueue Q) {

	//��ͷָ�����βָ���غϣ��������Ϊ��
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}