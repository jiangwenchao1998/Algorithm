#include <iostream>
using namespace std;

typedef struct PNode {
    float coef; //系数
    int expen;  //指数
    struct PNode *next; //指针域
}PNode, *Polynomial;

/**
 * 创建多项式链表
 * 1.创建一个只有头节点的空链表
 * 2.根据多项式的项的个数 n, 循环 n 次执行以下操作：
 *      ● 生成一个新节点
 *      ● 输入多项式当前项的系数和指数赋给新结点 *s 的数据域
 *      ● 设置一前驱指针 pre, 用于指向待找到的第一个大于输入项指数的结点的前驱, pre 初值指向头节点
 *      ● 指针 q 初始化, 指向首元结点
 *      ● 循链向下逐个比较链表中当前结点与输入项指数, 找到第一个输入项指数的结点 *q
 *      ● 将输入项结点 *s 插入到结点 *q 之前
 *
 * @return
 */
 void CreatePoly(Polynomial &P, int n) {
     P = new PNode;
     P->next = NULL;    //建立一个带头结点的单链表
    for (int i = 1; i <= n; ++i) {  //一次输入 n 个非零项
        Polynomial s = new PNode;    //生成一个新结点
        cin >> s->coef >> s->expen;  //输入系数与指数
        Polynomial pre = P; // pre 用于保存 q 的前驱, 初值为头节点
        Polynomial q = P->next; // q 初始化, 指向首元结点
        while (q && q->expen < s->expen) {  //通过比较指数找到第一个大于输入项指数的项 *q
            pre = q;
            q = q->next;
        }
        s->next = q;    //将输入项 s 插入到 q 和其前驱结点 pre 之间
        pre->next = s;
    }
 }

int main() {
    Polynomial P = NULL;
    int n;
    cin >> n;
    CreatePoly(P, n);
}