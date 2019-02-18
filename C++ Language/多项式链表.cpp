#include <iostream>
using namespace std;

typedef struct PNode {
    float coef; //ϵ��
    int expen;  //ָ��
    struct PNode *next; //ָ����
}PNode, *Polynomial;

/**
 * ��������ʽ����
 * 1.����һ��ֻ��ͷ�ڵ�Ŀ�����
 * 2.���ݶ���ʽ����ĸ��� n, ѭ�� n ��ִ�����²�����
 *      �� ����һ���½ڵ�
 *      �� �������ʽ��ǰ���ϵ����ָ�������½�� *s ��������
 *      �� ����һǰ��ָ�� pre, ����ָ����ҵ��ĵ�һ������������ָ���Ľ���ǰ��, pre ��ֵָ��ͷ�ڵ�
 *      �� ָ�� q ��ʼ��, ָ����Ԫ���
 *      �� ѭ����������Ƚ������е�ǰ�����������ָ��, �ҵ���һ��������ָ���Ľ�� *q
 *      �� ���������� *s ���뵽��� *q ֮ǰ
 *
 * @return
 */
 void CreatePoly(Polynomial &P, int n) {
     P = new PNode;
     P->next = NULL;    //����һ����ͷ���ĵ�����
    for (int i = 1; i <= n; ++i) {  //һ������ n ��������
        Polynomial s = new PNode;    //����һ���½��
        cin >> s->coef >> s->expen;  //����ϵ����ָ��
        Polynomial pre = P; // pre ���ڱ��� q ��ǰ��, ��ֵΪͷ�ڵ�
        Polynomial q = P->next; // q ��ʼ��, ָ����Ԫ���
        while (q && q->expen < s->expen) {  //ͨ���Ƚ�ָ���ҵ���һ������������ָ������ *q
            pre = q;
            q = q->next;
        }
        s->next = q;    //�������� s ���뵽 q ����ǰ����� pre ֮��
        pre->next = s;
    }
 }

int main() {
    Polynomial P = NULL;
    int n;
    cin >> n;
    CreatePoly(P, n);
}