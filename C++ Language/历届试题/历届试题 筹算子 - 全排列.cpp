/**
     ����ʽ

         B      DEF
    A + --- + ------- = 10
         C      GHI

    �����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�

    ���磺
    6+8/3+952/714 ����һ�ֽⷨ��
    5+3/1+972/486 ����һ�ֽⷨ��

    �����ʽһ���ж����ֽⷨ��

    ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int sum = 0;
    do {
        int a = arr[0], b = arr[1], c = arr[2], d = arr[3]*100 + arr[4]*10 + arr[5], e = arr[6]*100 + arr[7]*10 + arr[8];
        if (a*c*e + b*e +d*c == 10*c*e) {
            sum++;
        }
    }while (next_permutation(arr,arr+9) );
    cout << sum;
    return 0;
}
/**
 * ����:
 *      1.ȫ��������
 *      2.ע�⾫������
 *      3.����⻹����ʹ�� DFS �㷨
 */