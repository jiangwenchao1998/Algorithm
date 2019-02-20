#include <iostream>
using namespace std;

#define MAXSIZE 100 //˳��ջ�洢�ռ�ĳ�ʼ������
#define Status int
#define SElemType int
#define OK 1;
#define ERROR 0;

typedef struct {
    SElemType *base;    //ջ��ָ��
    SElemType *top;     //ջ��ָ��
    int stacksize;      //ջ���õ��������
}SqStack;

/**
 * ˳��ջ�ĳ�ʼ��
 * @return
 */
Status InitStack(SqStack *S) {
    //����һ����ջ
    S->base = new SElemType[MAXSIZE];   //Ϊ˳��ջ��̬����һ���������Ϊ MAXSIZE ������ռ�
    if (!S->base)   //�洢����ʧ��
        exit(-1);
    S->top = S->base;       //top ��ʼΪ base, ��ջ
    S->stacksize = MAXSIZE;     //stacksize ��Ϊջ��������� MAXSIZE
    return OK;
}

/**
 * ˳��ջ����ջ
 * @return
 */
Status Push(SqStack &S, SElemType e) {
    //����Ԫ�� e Ϊ�µ�ջ��Ԫ��
    if (S.top - S.base == S.stacksize) //ջ��
        return ERROR;
    *S.top++ = e;  //Ԫ�� e ѹ��ջ��, ��ջ��Ԫ�ظ��� e
}

 /**
  * ˳��ջ�ĳ�ջ
  * @return
  */
 Status Pop(SqStack &S, SElemType &e) {
     //ɾ�� S ��ջ��Ԫ��, �� e ������ֵ
     if (S.top == S.base)   //ջ��
         return ERROR;
     e = *--S.top;  //ջ��ָ��� 1, ��ջ��Ԫ�ظ��� e
     return OK;
 }

 /**
  * ȡ˳��ջ��ջ��Ԫ��
  * @return
  */
 Status GetTop(SqStack S) {
     //���� S ��ջ��Ԫ��, ���޸�ջ��ָ��
     if (S.top != S.base)
         return *(S.top - 1);
 }

int main() {
    SqStack S;
    InitStack(&S);
    Push(S, 3);
    SElemType e;
    Pop(S, e);
    cout << e;
}