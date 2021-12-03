#pragma once
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
	BiTNode() :data(), lchild(), rchild() {} //无参数初始化时调用
	BiTNode(char val) {  //有参数初始化时调用
		data = val;
		lchild = NULL;
		rchild = NULL;
	}
}BiTNode, * BiTree;