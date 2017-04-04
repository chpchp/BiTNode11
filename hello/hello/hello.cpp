// hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<stdio.h
#include <stdlib.h>
#include <stdio.h>

//二叉树结点结构
typedef struct BiTNode {
	char ch;//结点数据
	struct BiTNode *lchild;//左孩子
	struct BiTNode *rchild;//右孩子
}BiTNode,*BiTree;

void AddBiTree(BiTree, BiTNode *);//创建二叉树
void PreOrderTraverse(BiTNode *);//前序遍历
void InOrderTraverse(BiTNode *);//中序遍历
void PostOrderTraverse(BiTNode *);//后序遍历


int main()
{
	char ch; //结点数据
	BiTree T,p;//树T，和临时树p
	printf("请输入结点内容（以空格为结束标识）：");
	scanf("%c", &ch);//读入用户输入
	T = NULL;

	while (ch != ' ') {//判断输入
		//创建新节点
		if (p = (BiTNode *)malloc(sizeof(BiTNode))) {
			p->ch = ch;
			p->lchild = NULL;
			p->rchild = NULL;
		}
		else
		{
			printf("内存分配失败。\n");
			exit(0);
		}
		if (T == NULL)
			T = p;
		else
			AddBiTree(T, p);
		scanf("%c", &ch);//读入用户输入
	}
	//输出遍历
	printf("前序遍历：\n");
	PreOrderTraverse(T);
	printf("\n中序遍历：\n");
	InOrderTraverse(T);
	printf("\n后序遍历：\n");
	PostOrderTraverse(T);
	
    return 0;
}


//前序遍历
void PreOrderTraverse(BiTree T)
{
	if (T) {
		printf("%c", T->ch);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//创建二叉树
void AddBiTree(BiTree T, BiTree p)
{
	if ((p->ch <= T->ch) && (T->lchild != NULL))
		AddBiTree(T->lchild, p);
	else if ((p->ch <= T->ch) && (T->lchild == NULL))
		T->lchild = p;
	else if (T->rchild != NULL)
		AddBiTree(T->rchild, p);
	else T->rchild = p;
}

//中序遍历
void InOrderTraverse(BiTree T)
{
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%c", T->ch);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->ch);
	}
}