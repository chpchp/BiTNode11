// hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<stdio.h
#include <stdlib.h>
#include <stdio.h>

//���������ṹ
typedef struct BiTNode {
	char ch;//�������
	struct BiTNode *lchild;//����
	struct BiTNode *rchild;//�Һ���
}BiTNode,*BiTree;

void AddBiTree(BiTree, BiTNode *);//����������
void PreOrderTraverse(BiTNode *);//ǰ�����
void InOrderTraverse(BiTNode *);//�������
void PostOrderTraverse(BiTNode *);//�������


int main()
{
	char ch; //�������
	BiTree T,p;//��T������ʱ��p
	printf("�����������ݣ��Կո�Ϊ������ʶ����");
	scanf("%c", &ch);//�����û�����
	T = NULL;

	while (ch != ' ') {//�ж�����
		//�����½ڵ�
		if (p = (BiTNode *)malloc(sizeof(BiTNode))) {
			p->ch = ch;
			p->lchild = NULL;
			p->rchild = NULL;
		}
		else
		{
			printf("�ڴ����ʧ�ܡ�\n");
			exit(0);
		}
		if (T == NULL)
			T = p;
		else
			AddBiTree(T, p);
		scanf("%c", &ch);//�����û�����
	}
	//�������
	printf("ǰ�������\n");
	PreOrderTraverse(T);
	printf("\n���������\n");
	InOrderTraverse(T);
	printf("\n���������\n");
	PostOrderTraverse(T);
	
    return 0;
}


//ǰ�����
void PreOrderTraverse(BiTree T)
{
	if (T) {
		printf("%c", T->ch);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//����������
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

//�������
void InOrderTraverse(BiTree T)
{
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%c", T->ch);
		InOrderTraverse(T->rchild);
	}
}

//�������
void PostOrderTraverse(BiTree T)
{
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->ch);
	}
}