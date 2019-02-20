#include <iostream>
using namespace std;

#define MAXSIZE 100 //顺序栈存储空间的初始分配量
#define Status int
#define SElemType int
#define OK 1;
#define ERROR 0;

typedef struct {
    SElemType *base;    //栈底指针
    SElemType *top;     //栈顶指针
    int stacksize;      //栈可用的最大容量
}SqStack;

/**
 * 顺序栈的初始化
 * @return
 */
Status InitStack(SqStack *S) {
    //构造一个空栈
    S->base = new SElemType[MAXSIZE];   //为顺序栈动态分配一个最大容量为 MAXSIZE 的数组空间
    if (!S->base)   //存储分配失败
        exit(-1);
    S->top = S->base;       //top 初始为 base, 空栈
    S->stacksize = MAXSIZE;     //stacksize 置为栈的最大容量 MAXSIZE
    return OK;
}

/**
 * 顺序栈的入栈
 * @return
 */
Status Push(SqStack &S, SElemType e) {
    //插入元素 e 为新的栈顶元素
    if (S.top - S.base == S.stacksize) //栈满
        return ERROR;
    *S.top++ = e;  //元素 e 压入栈顶, 将栈顶元素赋给 e
}

 /**
  * 顺序栈的出栈
  * @return
  */
 Status Pop(SqStack &S, SElemType &e) {
     //删除 S 的栈顶元素, 用 e 返回其值
     if (S.top == S.base)   //栈空
         return ERROR;
     e = *--S.top;  //栈顶指针减 1, 将栈顶元素赋给 e
     return OK;
 }

 /**
  * 取顺序栈的栈顶元素
  * @return
  */
 Status GetTop(SqStack S) {
     //返回 S 的栈顶元素, 不修改栈顶指针
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